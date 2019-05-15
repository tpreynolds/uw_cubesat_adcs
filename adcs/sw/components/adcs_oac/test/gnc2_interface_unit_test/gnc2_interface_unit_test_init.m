% Unit test file for GNC-2 interface library
%
% T. Reynolds -- RAIN Lab

% problem parameters stored in init_SOACer
N = 10; % number of discretization nodes
w_max = 0.1;
T_max = 2.3e-3;
Jw    = diag([2.9382e-5,2.9382e-5,2.9382e-5]);
J     = [ 0.0338    -4.884e-05 -7.393e-05;
          -4.884e-05  0.0346     7.124e-06;
          -7.393e-05  7.124e-06  0.0075 ]; % kg m2

rng(2) % for repeatability of random IC

sc_mode = 33;

% initial conditions
ax  = [1;1;1]./norm([1;1;1]);
ang = 60;
quat_in  = [ cosd(ang/2); sind(ang/2).*ax ];
omega_in  = zeros(3,1);%0.01.*randn(3,1);
Om0 = 0.10471975511966 * [ 1000; 1000; 1000 ]; % rad/s
hw_in = Jw * Om0;

% final conditions
quat_cmd  = [ 1.0; 0.0; 0.0; 0.0 ];
omega_cmd  = [ 0.0; 0.0; 0.0 ];

% inertial sun vector
sI_unit  = [ 1.0; 0.0; 0.0 ];

% epoch and GPS time
GPS_epoch = sim_params.environment.sgp4.gps_time;

% Load sim and set run time
run_time    = 25;%soac_params.s_max;
mdl         = 'gnc2_interface_unit_test';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));

% run test case
% sim(mdl);

%% analyze results

u_opt = command_torque;
x_opt = command_state;

xf = x_opt(end,:);
qf = xf(1:4);
wf = xf(5:7);
hwf = xf(8:10);

% Plot
close all
figure
subplot(3,1,1), hold on, grid on
% plot(T,X(:,1:4),'LineWidth',1)
plot(tout,x_opt(:,1:4),'LineWidth',1)
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(3,1,2), hold on, grid on
plot(tout,x_opt(:,5:7),'LineWidth',1)
% plot(OAC.t,OAC.inertia\xopt(5:7,:),'ko','MarkerSize',3)
plot([0 tout(end)],[OAC.w_max OAC.w_max],'r--','LineWidth',1)
plot([0 tout(end)],[-OAC.w_max -OAC.w_max],'r--','LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity')
subplot(3,1,3), hold on, grid on
% plot(T,X(:,8:10),'LineWidth',1)
plot(tout,x_opt(:,8:10),'LineWidth',1)
xlabel('Time [s]')
title('Wheel Momentum')

figure, hold on, grid on
plot(tout,u_opt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')


