% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab
clear variables; close all;
% global my_ECOS

OAC         = struct;
OAC.N       = 10;
OAC.Nx      = 10;
OAC.Nu      = 3;
OAC.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
               -4.884e-05  0.0346     7.124e-06;
               -7.393e-05  7.124e-06  0.0075 ]; % bus inertia
OAC.Jw      = diag([2.9382e-05,2.9382e-05,2.9382e-05]);
OAC.Om0     = 0.10471975511966 * [ 1000;1000;1000 ]; % initial wheel speeds [rad/s]
OAC.T_max   = 3.2e-3; % Nm
OAC.s_min   = 15; % s
OAC.s_max   = 20; % s
OAC.method  = 'linear';

% q0  = Q_rand(4);
n   = [1;1;1]./norm([1;1;1]);
q0  = [ cosd(60/2); sind(60/2).*n ];
hb0  = [ 0.0; 0.0; 0.0 ];
hw0 = OAC.Jw * OAC.Om0;
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
hbf  = [ 0.0; 0.0; 0.0 ];

% Constraints
Hq      = [ eye(4) zeros(4,6) ];
xI      = [ 1.0; 0.0; 0.0 ];        % Inertial vector
yB      = [ 0.0; 0.0; -1.0 ];       % Body vector
yyB     = [ 0.5*sqrt(2); 0.5*sqrt(2); 0.0 ]; % Body vector
amin    = deg2rad(60);              % min. separating angle
amax    = deg2rad(90);              % max. separating angle
Me      = [ xI*yB'+yB*xI'-(xI'*yB)*eye(3)   skew(xI)*yB;
            (skew(xI)*yB)'                  xI'*yB ] - cos(amin)*eye(4);
Mi      = [ xI*yyB'+yyB*xI'-(xI'*yyB)*eye(3)   skew(xI)*yyB;
            (skew(xI)*yyB)'                  xI'*yyB ] - cos(amax)*eye(4);
ME      = Me + 2*eye(4);     % M_tilde
MI      = 2*eye(4) - Mi;     % M_tilde
% ME      = sqrtm(ME);        % Exclusion constraint matrix
% MI      = sqrtm(MI);

% Initial trajectory
x0      = zeros(OAC.Nx,OAC.N);
u0      = zeros(OAC.Nu,OAC.N);
s0      = OAC.s_max;
OAC.t0  = 0;
OAC.tf  = s0; 
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
OAC.tau = linspace(OAC.t0,1,OAC.N);
[qb,flag] = Q_SLERP(q0,qf,OAC.t);
for k = 1:OAC.N-1
    x0(:,k)   = [ qb(:,k); zeros(3,1); hw0 ];
    u0(:,k)     = zeros(3,1);
end
x0 = reshape(x0,OAC.Nx*OAC.N,1);
u0 = reshape(u0,OAC.Nu*OAC.N,1);
ecos_time = 0.0;

% initial trust region
W = 1e-1 * ones(OAC.N,1);
% Rmin = 0.01;

% Successive Loop
for iter = 1:10
    
    OAC.X   = x0;
    OAC.U   = u0;
    OAC.s   = s0;
    [EH,BE,ES,ZE,~] = foh_p(OAC);
    
    % update trust region
%     for k = 2:OAC.N
%         if (R(k) <= Rmin)
%             W(k) = 1/Rmin;
%         else
%             W(k) = 1/R(k);
%         end
%     end
    
    cvx_clear
    cvx_tic;
        cvx_begin quiet
        cvx_solver('ecos')
        cvx_precision('low')
    
        % Variables
        variables x(OAC.Nx*OAC.N) u(OAC.Nu*OAC.N) v(OAC.Nx*OAC.N)
        variable s nonnegative
        variable g nonnegative
%         variable ee(OAC.N) nonnegative
    
        % Cost function
        minimize( g + 1e2*norm(v,1) )% + 5e0*sum(ee) )
    
        subject to
    
        % Initial conditions
        x(1:4)  == q0;
        x(5:7)  == hb0;
        x(8:10) == hw0;
    
        % Final conditions
        x(OAC.Nx*(OAC.N-1)+(1:4)) == qf;
        x(OAC.Nx*(OAC.N-1)+(5:7)) == hbf;
    
        % Time bound
        OAC.s_min <= s <= OAC.s_max;
    
        % Dynamics
        x == EH*x + BE*u + ES*s + ZE + v;
    
        % Constraints
        for k = 1:OAC.N
            xk = x(OAC.Nx*(k-1)+1:OAC.Nx*k);
%             uk = u(OAC.Nu*(k-1)+1:OAC.Nu*k);
            norm(u(OAC.Nu*(k-1)+1:OAC.Nu*k),inf) <= OAC.T_max;
%             xk'*Hq'*ME*Hq*xk <= 2;
            xk'*Hq'*MI*Hq*xk <= 2;
            norm(OAC.inertia\xk(5:7),inf) <= 0.3;
            % Trust region
%             (uk-u0(OAC.Nu*(k-1)+1:OAC.Nu*k))'*(uk-u0(OAC.Nu*(k-1)+1:OAC.Nu*k)) <= ee(k);
        end
        % Control effort
        u'*u <= g;
%         -g <= u <= g;
    
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
    if( (norm(v,1) < 1e-5) && (diff < 1e-1) )
        fprintf('Converged.\n\n')
        break;
    end
end

% Print solution time
fprintf('Total Solver time: %g s\n',ecos_time)

% Integrate through ODE
T       = linspace(0,s,100);
OAC.tf  = s;
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
xopt    = reshape(full(x),OAC.Nx,OAC.N);
uopt    = reshape(full(u),OAC.Nu,OAC.N);
X = rk4(@(t,y)Q_ode_p(OAC,t,y,uopt,OAC.t),T,full(x(1:OAC.Nx)));

% Plot
close all
figure(1)
subplot(3,1,1), hold on, grid on
plot(T,X(:,1:4),'LineWidth',1)
plot(OAC.t,xopt(1:4,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(3,1,2), hold on, grid on
plot(T,OAC.inertia\X(:,5:7)','LineWidth',1)
plot(OAC.t,OAC.inertia\xopt(5:7,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Angular Velocity')
subplot(3,1,3), hold on, grid on
plot(T,X(:,8:10),'LineWidth',1)
plot(OAC.t,xopt(8:10,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Wheel Momentum')

figure(2), hold on, grid on
plot(OAC.t,uopt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')