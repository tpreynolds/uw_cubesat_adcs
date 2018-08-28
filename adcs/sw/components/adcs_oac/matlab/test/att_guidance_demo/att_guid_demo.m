% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab

P.Nx        = 7;
P.Nu        = 3;
P.inertia   = fsw_params.bus.inertia;

% q0  = [ 0.9206; 0.3454; -0.0286; 0.1799 ];
q0  = [ cosd(10/2); sind(10/2); 0; 0 ];
w0  = [ 0.0; 0.0; 0.0 ];
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
wf  = [ 0.0; 0.0; 0.0 ];

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));

P.N   = ceil(ang_err/3);
P.t0  = 0;
P.tf  = 10; % WAG
P.t   = linspace(P.t0,P.tf,P.N);
P.dt  = P.t(2);

[qb,flag] = Q_SLERP(q0,qf,P.t);

EH  = zeros(P.N*P.Nx,P.N*P.Nx);
EH(1:P.Nx,1:P.Nx)   = eye(P.Nx);
BE  = zeros(P.N*P.Nx,P.N*P.Nu);
ZE  = zeros(P.N*P.Nx,1);

for k = 1:P.N-1
    qk  = qb(:,k);
    qk_skew = [ qk(1)   -qk(2:4)';
                qk(2:4) skew(qk(2:4))+qk(1)*eye(3) ];
    wk  = qk_skew \ ( (2/P.dt)*(qb(:,k+1) - qk) );
    wk  = wk(2:4);
    uk  = zeros(3,1);
    [Ak,Bk,zk] = Q_linearize(P,P.t(k),[qk;wk],uk);
    EH(P.Nx*k+1:P.Nx*(k+1),P.Nx*(k-1)+1:P.Nx*k)  = Ak;
    BE(P.Nx*k+1:P.Nx*(k+1),P.Nu*(k-1)+1:P.Nu*k)  = Bk;
    ZE(P.Nx*k+1:P.Nx*(k+1),1)                    = zk;
end
cvx_clear
cvx_tic;
cvx_begin quiet
    cvx_solver('ecos')
    cvx_precision('low')
    
    % Variables
    variables x(P.Nx*P.N) u(P.Nu*P.N) 
    variable s(P.N) nonnegative
    
    % Cost function
    minimize( sum(s) )
    
    % Constraints
    x(1:P.Nx) == [ q0; w0 ];  
    x  == EH*x + BE*u + ZE;
    x(end-(P.Nx-1):end) == [ qf; wf ];
    
    for k = 1:P.N
        xk = x(P.Nx*(k-1)+1:P.Nx*k);
        uk = u(P.Nu*(k-1)+1:P.Nu*k);
        norm(uk,2) <= s(k);
%         norm(xk(5:7),inf) <= 0.3;
%         norm(uk,inf) <= 1e-3;
    end
    
    cvx_end
    sol_time = cvx_toc;
    
    fprintf('Total time: %g s\n',sol_time(1))
    fprintf('Pre-solve: %g s \n',sol_time(4))
    fprintf('Solver time: %g s\n',sol_time(5))
