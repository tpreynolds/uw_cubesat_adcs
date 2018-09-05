% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab

OAC.Nx        = 7;
OAC.Nu        = 3;
OAC.inertia   = fsw_params.bus.inertia;
OAC.method    = 'linear';

%q0  = [ 0.9206; 0.3454; -0.0286; 0.1799 ];
q0  = [ cosd(60/2); sind(60/2); 0; 0 ];
w0  = [ 0.0; 0.0; 0.0 ];
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
wf  = [ 0.0; 0.0; 0.0 ];

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));

OAC.N   = ceil(ang_err/5);
OAC.t0  = 0;
OAC.tf  = 60; % WAGq
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);

% Initial trajectory
x0  = zeros(7,OAC.N);
u0  = zeros(3,OAC.N);
[qb,flag] = Q_SLERP(q0,qf,OAC.t);
for k = 1:OAC.N-1
    x0(:,k)   = [ qb(:,k); zeros(3,1) ];
    u0(:,k)     = zeros(3,1);
end
OAC.X    = reshape(x0,OAC.Nx*OAC.N,1);
OAC.U    = reshape(u0,OAC.Nu*OAC.N,1);
[EH,BEm,BEp,ZE] = foh(OAC);


cvx_clear
cvx_tic;
cvx_begin quiet
    cvx_solver('ecos')
    cvx_precision('low')
    
    % Variables
    variables x(OAC.Nx,OAC.N) u(OAC.Nu,OAC.N) 
    variable s(OAC.N) nonnegative
    
    % Cost function
    minimize( sum(s) )
    
    % Constraints
    x(:,1)      == [ q0; w0 ];
    x(:,OAC.N)  == [ qf; wf ];
    
    for k = 1:OAC.N-1
        xk  = x(:,k);
        xkp = x(:,k+1);
        uk  = u(:,k);
        ukp = u(:,k+1);
        Ak  = EH(:,:,k);
        Bkm = BEm(:,:,k);
        Bkp = BEp(:,:,k);
        Zk  = ZE(:,:,k);
        
        % Dynamics
        xkp == Ak * xk + Bkm * uk + Bkp * ukp + Zk;
        
        % Constraints
        norm(uk,2)  <= s(k);
        s(k)        <= 1e-2;
%         norm(xk(5:7),inf) <= 0.3;
    end
    
    cvx_end
    sol_time = cvx_toc;
    
    fprintf('Total time: %g s\n',sol_time(1))
    fprintf('Pre-solve: %g s \n',sol_time(4))
    fprintf('Solver time: %g s\n',sol_time(5))
    
    % Integrate through ODE
    T = linspace(0,OAC.tf,100);
    X = rk4(@(t,y)Q_ode(OAC,t,y,u,OAC.t),T,[q0;w0]);
    
    % Plot
    close all
    figure(1)
    subplot(2,1,1), hold on, grid on
    plot(T,X(:,1:4),'LineWidth',1)
    xlabel('Time [s]')
    title('Attitude Quaternion')
    subplot(2,1,2), hold on, grid on
    plot(T,X(:,5:7),'LineWidth',1)
    xlabel('Time [s]')
    title('Angular Velocity')
    
