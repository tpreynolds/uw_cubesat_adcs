% ----------------------------------------------------------------------- %
%ZOH   zeroth order hold discretization
%
% Computes the matrices (A,B,S,Z) to numerically discretize a problem
% instance of the PDG problem about the most recent trajectory stored in
% sol.X and sol.U. Assumes a piecewise constant thrust command.
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
function [ EH,BE,ES,ZE ] = zoh( OAC )

% Problem dimensions
szeA    = OAC.Nx;
szeB1   = OAC.Nx;
szeB2   = OAC.Nu;
szeS    = OAC.Nx;
szeZ    = OAC.Nx;

% Relevant info from structs
X       = OAC.X;
U       = OAC.U;
s       = OAC.s;
N       = OAC.N;
time    = OAC.tau;
len     = length(time)-1;
x0      = X(1:szeA);

% Set sizes for each discrete matrix
EH                  = zeros(szeA*(len+1),szeA*(len+1));
EH(1:szeA,1:szeA)   = eye(szeA);
BE                  = zeros(szeA*(len+1),szeB2*(len+1));
ES                  = zeros(szeA*(len+1),1);
ZE                  = zeros(szeA*(len+1),1);

% Initial conditions
A0  = eye(szeA);
B0  = zeros(szeB1*szeB2,1);
S0  = zeros(szeS,1);
Z0  = zeros(szeZ,1);
P0  = [x0(:); A0(:); B0(:); S0(:); Z0(:)];

for k = 1:len   
    u       = U(szeB2*(k)+1:szeB2*(k+1));
    u       = reshape(u,OAC.Nu,1);
    tspan   = linspace(time(k), time(k+1), N);

    F   = rk4(@(t,X)deriv(t,X,u,s,OAC),tspan,P0(:));
    
    xF  = X(szeA*k+1:szeA*(k+1)); % Restart each window with previous soln
    AF  = F(end,szeA+1:szeA*szeA+szeA);
    BF  = F(end,szeA*(szeA+1)+1:szeA*(szeA+1)+szeB1*szeB2);
    SF  = F(end,szeA*(szeA+1)+szeB1*szeB2+1:szeA*(szeA+1)+szeB1*szeB2+szeS);
    ZF  = F(end,szeA*(szeA+1)+szeB1*szeB2+szeS+1:end);
    
    % Reshape to matrices
    Ad  = reshape(AF,szeA,szeA);
    Bd  = Ad*reshape(BF,szeB1,szeB2);
    Sd  = Ad*reshape(SF,szeS,1);
    Zd  = Ad*reshape(ZF,szeZ,1);
    
    % redefine initial condition
    P0 = [xF(:); A0(:); B0(:); S0(:); Z0(:)];
    
    % fill up matrices
    EH(szeA*(k)+1:szeA*(k+1),szeA*(k-1)+1:szeA*k)       = Ad;
    BE(szeA*(k)+1:szeA*(k+1),szeB2*(k)+1:szeB2*(k+1))   = Bd;
    ES(szeA*(k)+1:szeA*(k+1))                           = Sd;
    ZE(szeA*(k)+1:szeA*(k+1))                           = Zd;
end


end

function DX = deriv(t,X,u,s,OAC)       
    Nx  = OAC.Nx;
    x   = X(1:Nx);
    
%     [f,A,B,Z] = get_f_vals(t,x,u,PDG);
    [A,B,f]     = Q_linearize(t,x,u,OAC);
    Z           = - A*x - B*u;
    
    PHI = reshape(X(Nx+1:Nx+Nx*Nx),size(A));
       
    xdot    = s*f;
    PHI_dot = (s*A)*PHI;
    Bd_dot  = PHI\(s*B);
    Sd_dot  = PHI\f;
    Zd_dot  = PHI\(s*Z);
    
    DX  = [xdot(:); PHI_dot(:); Bd_dot(:); Sd_dot(:); Zd_dot(:)];
end

% % ----- f expressions ----- %
% 
% function [f,A,B,Z] = get_f_vals(t,x,u,PDG)    
%     
%     % Compute A and B
%     A = dfdx_REG(x,u,PDG);
%     B = dfdu_REG(x,u,PDG);
%     
%     % Compute f
%     f       = f_REG(PDG,t,x,u);  
%     
%     % Compute remaining terms in Taylor series
%     Z       = - A*x - B*u;
%                            
% end
% 
% % ------------------------- %
