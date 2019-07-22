function [ EH,BE,ES,ZE,R ] = foh_p( OAC )
% ----------------------------------------------------------------------- %
%FOH   first order hold discretization
%
% FOH(ctrl,sol) Computes the matrices (A,B,S,Z) to numerically discretize 
% a problem instance of the PDG problem about the most recent trajectory 
% stored in sol.X and sol.U. Assumes a linear interpolation of the thrust 
% between control nodes.
%
% These give the first order Taylor series of the dynamics
% at the time nodes dictated by ctrl.N and correspond to a discrete time
% LTV system approximating the nonlinear dynamics.
%
% Inputs: ctrl, sol
% Outputs: 
%   - EH (N*Nx by N*Nx)
%   - BE (N*Nu by N*Nu)
%   - ES (N*Nx by 1)
%   - ZE (N*Nx by 1)
%
% T. Reynolds -- RAIN Lab
% ----------------------------------------------------------------------- %

% Problem dimensions
szeA  = OAC.Nx;
szeB1 = OAC.Nx;
szeB2 = OAC.Nu;
szeS  = OAC.Nx;
szeZ  = OAC.Nx;

% Relevant info from structs
X       = OAC.X;
U       = OAC.U;
s       = OAC.s;
N       = OAC.N;
time    = OAC.tau;
len     = length(time)-1;
x0      = X(1:szeA);

% % Set sizes for each discrete matrix
% EH                  = zeros(szeA,szeA,len);
% BEp                 = zeros(szeA,szeB2,len);
% BEm                 = zeros(szeA,szeB2,len);
% ES                  = zeros(szeA,1,len);
% ZE                  = zeros(szeA,1,len);

% Set sizes for each discrete matrix
EH                  = zeros(szeA*(len+1),szeA*(len+1));
EH(1:szeA,1:szeA)   = eye(szeA);
BE                  = zeros(szeA*(len+1),szeB2*(len+1));
ES                  = zeros(szeA*(len+1),1);
ZE                  = zeros(szeA*(len+1),1);
R                   = zeros(N,1);

% Initial conditions
A0      = eye(szeA);
B0p     = zeros(szeB1*szeB2,1);
B0m     = zeros(szeB1*szeB2,1);
S0      = zeros(szeS,1);
Z0      = zeros(szeZ,1);
P0      = [x0(:); A0(:); B0p(:); B0m(:); S0(:); Z0(:)];

for k = 1:len
    um  = U(szeB2*(k-1)+1:szeB2*(k));
    up  = U(szeB2*(k)+1:szeB2*(k+1));
    u   = [reshape(um,3,1) reshape(up,3,1)];
    tspan   = linspace(time(k), time(k+1), N);
    
    F   = rk4(@(t,X)deriv(t,X,u,tspan,s,OAC),tspan,P0(:));
    
    xF      = F(end,1:szeA);
    AF      = F(end,szeA+1:szeA*(szeA+1));
    BFp     = F(end,szeA*(szeA+1)+1:szeA*(szeA+1)+szeB1*szeB2);
    BFm     = F(end,szeA*(szeA+1)+szeB1*szeB2+1:szeA*(szeA+1)+2*szeB1*szeB2);
    SF      = F(end,szeA*(szeA+1)+2*szeB1*szeB2+1:szeA*(szeA+1)+2*szeB1*szeB2+szeS);
    ZF      = F(end,szeA*(szeA+1)+2*szeB1*szeB2+szeS+1:end);
    
    % Reshape to matrices
    xd   = reshape(xF,szeA,1);
    Ad   = reshape(AF,szeA,szeA);
    Bdp  = Ad*reshape(BFp,szeB1,szeB2);
    Bdm  = Ad*reshape(BFm,szeB1,szeB2);
    Sd   = Ad*reshape(SF,szeS,1);
    Zd   = Ad*reshape(ZF,szeZ,1);
    
    % Redefine initial condition
    x0 = X(szeA*k+1:szeA*(k+1));
    P0 = [x0(:); A0(:); B0p(:); B0m(:); S0(:); Z0(:)];
    
%     % Fill up matrices
%     EH(:,:,k)   = Ad;
%     BEm(:,:,k)  = Bdm;
%     BEp(:,:,k)  = Bdp;
%     ES(:,:,k)   = Sd;
%     ZE(:,:,k)   = Zd;
    
    % Fill up matrices
    EH(szeA*(k)+1:szeA*(k+1),szeA*(k-1)+1:szeA*k)       = Ad;
    BE(szeA*(k)+1:szeA*(k+1),szeB2*(k-1)+1:szeB2*(k))   = Bdm;
    BE(szeA*(k)+1:szeA*(k+1),szeB2*(k)+1:szeB2*(k+1))   = Bdp;
    ES(szeA*(k)+1:szeA*(k+1))                           = Sd;
    ZE(szeA*(k)+1:szeA*(k+1))                           = Zd;
    R(k+1)                                              = norm(xd-x0,2);
end


end

function DX = deriv(t,X,u,tspan,s,OAC)
    Nx  = OAC.Nx;
    x   = X(1:Nx);
    
    [f,A,Bp,Bm,Z] = get_f_vals(t,x,u,tspan,OAC);
    
    Phi = reshape(X(Nx+1:Nx+Nx*Nx),size(A));
       
    xdot        = s*f;
    Phi_dot     = (s*A)*Phi;
    Bdp_dot     = Phi\(s*Bp);
    Bdm_dot     = Phi\(s*Bm);
    Sd_dot      = Phi\f;
    Zd_dot      = Phi\(s*Z);
    
    DX      = [ xdot(:); Phi_dot(:); Bdp_dot(:);...
                Bdm_dot(:); Sd_dot(:); Zd_dot(:)];
end

function [f,A,Bp,Bm,Z] = get_f_vals(t,x,u,tspan,OAC)
    
    tkm     = tspan(1);
    tkp     = tspan(end);     
    lam_km  = (tkp - t)/(tkp - tkm);
    lam_kp  = (t - tkm)/(tkp - tkm);
    
    % Interpolate u
    uu  = zeros(3,1);
    for k = 1:3
        uu(k)   = interp1([tkm tkp],u(k,:),t,'linear');
    end

    % compute jacobian matrices
    if (OAC.Nx == 10)
        [A,B,f] = Q_linearize_p(t,x,uu,OAC);
    else
        [A,B,f] = Q_linearize(t,x,uu,OAC);
    end
    
    Bp  = lam_kp*B;
    Bm  = lam_km*B;
    
    % compute z
    Z   = - A*x - B*uu;
                           
end
