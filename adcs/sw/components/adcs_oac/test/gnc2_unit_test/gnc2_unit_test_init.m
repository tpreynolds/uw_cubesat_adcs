% Unit test file for GNC-2 library
%
% T. Reynolds -- RAIN Lab

% problem parameters stored in init_SOACer
N = 10; % number of discretization nodes
w_max = 0.3;
T_max = 1e-3;

rng(2) % for repeatability of random IC

% initial conditions
ax  = [1;1;1]./norm([1;1;1]);
ang = 30*randn;
q0  = [ cosd(ang/2); sind(ang/2).*ax ];
w0  = 0.01.*randn(3,1);

% final conditions
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
wf  = [ 0.0; 0.0; 0.0 ];

% inertial sun vector
sI  = [ 1.0; 0.0; 0.0 ];

% Load sim and set run time
run_time    = 1;
mdl         = 'gnc2_unit_test';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));

% run test case
sim(mdl);

%% analyze results
num_sims = size(x_star,1);
xopt = x_star(end,:);
uopt = u_star(end,:);
sopt = s_star(end,:);
exitcode = exitcode(end,:);

total_time = zeros(num_sims,1);
for k = 1:num_sims
    total_time(k) = sum(sol_times(k,:));
end
mean_time       = mean(total_time);
std_time        = std(total_time);
max_time        = max(total_time);
threesig_time   = 3*std_time;
hertz           = 1/(mean_time+threesig_time);
fprintf('===========================\n')
fprintf('SOACer UNIT TEST RESULTS:\n')
fprintf('===========================\n')
fprintf('Over %d trials: \n',num_sims)
fprintf('The mean total solution time is: %0.5f +/- %0.5f sec (3-sigma)\n',...
            mean_time,threesig_time)
fprintf('Able to call the function at: %0.2f Hz (3-sigma)\n\n',hertz)


% Integrate through ODE
T       = linspace(0,sopt,100);
xopt    = reshape(full(xopt),7,N);
uopt    = reshape(full(uopt),3,N);
ut      = linspace(0,sopt,N);
P.method  = 'linear';
P.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
              -4.884e-05  0.0346     7.124e-06;
              -7.393e-05  7.124e-06  0.0075 ];

% integrate solution through nonlinear dynamics
X = rk4(@(t,y)Q_ode(P,t,y,uopt,ut),T,full(xopt(1:7)));

% Plot
close all
figure(1)
subplot(2,1,1), hold on, grid on
plot(T,X(:,1:4),'LineWidth',1)
plot(ut,xopt(1:4,:),'k*','MarkerSize',3)
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(2,1,2), hold on, grid on
plot(T,X(:,5:7),'LineWidth',1)
plot(ut,xopt(5:7,:),'k*','MarkerSize',3)
plot([0 sopt],[w_max w_max],'r--','LineWidth',1)
plot([0 sopt],[-w_max -w_max],'r--','LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity')

figure(2), hold on, grid on
plot(ut,uopt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')