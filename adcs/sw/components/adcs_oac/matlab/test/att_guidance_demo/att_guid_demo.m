% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab
clear variables; close all;

OAC         = struct;
OAC.Nx      = 7;
OAC.Nu      = 3;
OAC.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
               -4.884e-05  0.0346     7.124e-06;
               -7.393e-05  7.124e-06  0.0075 ];
OAC.T_max   = 1e-2;
OAC.method  = 'linear';

% q0  = Q_rand();
q0  = [ cosd(60/2); sind(60/2); 0; 0 ];
w0  = [ 0.0; 0.0; 0.0 ];
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
wf  = [ 0.0; 0.0; 0.0 ];

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));
OAC.N   = ceil(ang_err/10);

% Constraints
Hq      = [ eye(4) zeros(4,3) ];
xI      = [ 1.0; 0.0; 0.0 ];        % Inertial vector
yB      = [ 0.0; 0.0; -1.0 ];       % Body vector
amax    = deg2rad(60);              % min. separating angle
Me      = [ xI*yB'+yB*xI'-(xI'*yB)*eye(3)   skew(xI)*yB;
            (skew(xI)*yB)'                  xI'*yB ] - cos(amax)*eye(4);
ME      = Me + 2*eye(4);     % M_tilde
% ME      = sqrtm(Mt);        % Exclusion constraint matrix

% Initial trajectory
x0      = zeros(7,OAC.N);
u0      = zeros(3,OAC.N);
s0      = 2*sqrt((pi/180)*ang_err);
OAC.t0  = 0;
OAC.tf  = s0; 
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
OAC.tau = linspace(OAC.t0,1,OAC.N);
[qb,flag] = Q_SLERP(q0,qf,OAC.t);
for k = 1:OAC.N-1
    x0(:,k)   = [ qb(:,k); zeros(3,1) ];
    u0(:,k)     = zeros(3,1);
end
x0 = reshape(x0,OAC.Nx*OAC.N,1);
u0 = reshape(u0,OAC.Nu*OAC.N,1);
ecos_time = 0.0;

% Successive Loop
for iter = 1:10

OAC.X   = x0;
OAC.U   = u0;
OAC.s   = s0;
[EH,BE,ES,ZE] = foh(OAC);

cvx_clear
cvx_tic;
cvx_begin quiet
    cvx_solver('ecos')
    cvx_precision('low')
    
    % Variables
    variables x(OAC.Nx*OAC.N) u(OAC.Nu*OAC.N) v(OAC.Nx*OAC.N)
    variable s nonnegative
%     variable eta_s
    
    % Cost function
    minimize( s  + 1e1*norm(v,1) ) %+ 1e-1*eta_s
    
    subject to
    
    % Initial conditions
    x(1:4) == q0;
    x(5:7) == w0;
    
    % Final conditions
    x(OAC.Nx*(OAC.N-1)+1:OAC.Nx*(OAC.N-1)+4) == qf;
    x(OAC.Nx*(OAC.N-1)+5:OAC.Nx*OAC.N) == wf;
    
    % Time trust region
%     (s-s0)'*(s-s0) <= eta_s;
    0.5*sqrt((pi/180)*ang_err) <= s <= 4*sqrt((pi/180)*ang_err);
    
    % Dynamics
    x == EH*x + BE*u + ES*s + ZE + v;
    
    % Constraints
    for k = 1:OAC.N        
        xk  = x(OAC.Nx*(k-1)+1:OAC.Nx*k);
        norm(u(OAC.Nu*(k-1)+1:OAC.Nu*k),inf) <= OAC.T_max;
        xk'*Hq'*Mt*Hq*xk <= 2;
%         norm(xk(5:7),inf) <= 0.3;
    end
    
    cvx_end
    sol_time = cvx_toc;
    
    % Difference from last solution
    diff        = norm(x - x0,1);
    ecos_time   = ecos_time + sol_time(5);
    x0 = full(x);
    u0 = full(u);
    s0 = s;
    
    % Display iter information
    fprintf('Iter: %d |',iter)
    fprintf(' Solver Time: %2.2g s |',sol_time(5))
    fprintf(' HoG: %02.2e |',norm(v,1))
    fprintf(' Diff: %02.2e |',diff)
    fprintf(' t_f: %2.2f \n',s)
    
    % Check exit condition
    if( (norm(v,1) < 1e-5) && (diff < 1e-5) )
        fprintf('Converged.\n\n')
        break;
    end
end

% Print solution time
fprintf('Total Solver time: %g s\n',ecos_time)

% Integrate through ODE
T = linspace(0,s,100);
OAC.tf  = s;
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
xopt    = reshape(full(x),OAC.Nx,OAC.N);
uopt    = reshape(full(u),OAC.Nu,OAC.N);
X = rk4(@(t,y)Q_ode(OAC,t,y,uopt,OAC.t),T,full(x(1:OAC.Nx)));

% Plot
close all
figure(1)
subplot(2,1,1), hold on, grid on
plot(T,X(:,1:4),'LineWidth',1)
plot(OAC.t,xopt(1:4,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(2,1,2), hold on, grid on
plot(T,X(:,5:7),'LineWidth',1)
plot(OAC.t,xopt(5:7,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Angular Velocity')

figure(2), hold on, grid on
plot(OAC.t,uopt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')


