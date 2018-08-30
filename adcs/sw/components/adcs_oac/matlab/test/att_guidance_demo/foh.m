function [ EH,BEm,BEp,ZE ] = foh( OAC )
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
szeZ  = OAC.Nx;

% Relevant info from structs
X       = OAC.X;
U       = OAC.U;
N       = OAC.N;
time    = OAC.t;
len     = length(time)-1;
x0      = X(1:szeA);

% Set sizes for each discrete matrix
EH                  = zeros(szeA,szeA,len);
BEp                 = zeros(szeA,szeB2,len);
BEm                 = zeros(szeA,szeB2,len);
ZE                  = zeros(szeA,1,len);

% Initial conditions
A0      = eye(szeA);
B0p     = zeros(szeB1*szeB2,1);
B0m     = zeros(szeB1*szeB2,1);
Z0      = zeros(szeZ,1);
P0      = [x0(:); A0(:); B0p(:); B0m(:); Z0(:)];

for k = 1:len
    um  = U(szeB2*(k-1)+1:szeB2*(k));
    up  = U(szeB2*(k)+1:szeB2*(k+1));
    u   = [reshape(um,3,1) reshape(up,3,1)];
    tspan   = linspace(time(k), time(k+1), N);
    
    F   = rk4(@(t,X)deriv(t,X,u,tspan,OAC),tspan,P0(:));
    
    xF      = X(szeA*k+1:szeA*(k+1)); 
    AF      = F(end,szeA+1:szeA*(szeA+1));
    BFp     = F(end,szeA*(szeA+1)+1:szeA*(szeA+1)+szeB1*szeB2);
    BFm     = F(end,szeA*(szeA+1)+szeB1*szeB2+1:szeA*(szeA+1)+2*szeB1*szeB2);
    ZF      = F(end,szeA*(szeA+1)+2*szeB1*szeB2+1:end);
    
    % Reshape to matrices
    Ad   = reshape(AF,szeA,szeA);
    Bdp  = Ad*reshape(BFp,szeB1,szeB2);
    Bdm  = Ad*reshape(BFm,szeB1,szeB2);
    Zd   = Ad*reshape(ZF,szeZ,1);
    
    % Redefine initial condition
    P0 = [xF(:); A0(:); B0p(:); B0m(:); Z0(:)];
    
    % Fill up matrices
    EH(:,:,k)   = Ad;
    BEm(:,:,k)  = Bdm;
    BEp(:,:,k)  = Bdp;
    ZE(:,:,k)   = Zd;
end


end

function DX = deriv(t,X,u,tspan,OAC)
    Nx  = OAC.Nx;
    x   = X(1:Nx);
    
    [f,A,Bp,Bm,Z] = get_f_vals(t,x,u,tspan,OAC);
    
    Phi = reshape(X(Nx+1:Nx+Nx*Nx),size(A));
       
    xdot        = f;
    Phi_dot     = A*Phi;
    Bdp_dot     = Phi\Bp;
    Bdm_dot     = Phi\Bm;
    Zd_dot      = Phi\Z;
    
    DX      = [ xdot(:); Phi_dot(:); Bdp_dot(:); Bdm_dot(:); Zd_dot(:)];
end

function [f,A,Bp,Bm,Z] = get_f_vals(t,x,u,tspan,OAC)
    
    tkm     = tspan(1);
    tkp     = tspan(end);     
    lam_km  = (tkp - t)/(tkp - tkm);
    lam_kp  = (t - tkm)/(tkp - tkm);
    
    % Interpolate u
    uu   = interp1([tkm tkp],u',t,'linear')';

    % compute jacobian matrices
    [A,B,f] = Q_linearize(t,x,uu,OAC);
    
    Bp  = lam_kp*B;
    Bm  = lam_km*B;
    
    % compute z
    Z       = f - A*x - B*uu;
                           
end
