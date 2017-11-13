%% PD Control unit test init file

%

% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 9.23.17
%% Load paths

clear variables; close all; clc;
set(0,'defaulttextinterpreter','latex');

% Start fresh
clear variables; close all; clc
addpath(genpath('../../../matlab/')) % adds the fsw libs
addpath(genpath('../../../../adcs_sim/matlab/')) % add the sim libs

run_test    = 1;


%% Test 1

if run_test == 1

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
J  = fsw_params.bus.inertia;
sim_params.dynamics.ic.rate_init = zeros(3,1);

% Choose damping ratio and natural frequency
z   = 1; % Critically damped
wn  = 0.02*2*pi; % Small natural frequency

fsw_params.control.pd_controller.p_gain  = -wn^2.*J;
fsw_params.control.pd_controller.d_gain  = -2*wn*z.*J;

% fsw_params.control.pd_controller.p_gain = -kp;
% fsw_params.control.pd_controller.d_gain = -kd;
temp    = randn(4,1);
sim_params.dynamics.ic.quat_init    = temp./norm(temp);
sim_params.dynamics.ic.quat_init    = [0; 0; 0; 1];

eul_angle   = deg2rad(10);
eul_axis    = [1; 0; 0];
fsw_params.bus.quat_commanded   = [sin(eul_angle/2)*eul_axis; cos(eul_angle/2)];

t_end   = 500;
% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'pd_control_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %

quat    = logsout.getElement('<quaternion>').Values.Data;
omega   = logsout.getElement('<body_rates>').Values.Data;
cmdu       = logsout.getElement('cmd_torque').Values.Data;
realu       = logsout.getElement('torque').Values.Data;
real_time   = logsout.getElement('torque').Values.Time;
cmdRPM     = squeeze(logsout.getElement('cmd_rpm').Values.Data);
realRPM     = logsout.getElement('real_RPM').Values.Data;

q_d     = fsw_params.bus.quat_commanded;
diff    = zeros(1,length(tout));
for i = 1:length(tout)
    q_diff  = quatmultiply(quatconj(q_d'),quat(i,:));
    diff(i) = norm( q_diff(2:4) ) ;
end


% ----- End Analysis ----- %

figure(1)
subplot(2,1,1)
plot(tout,quat)
title('Quaternion','FontSize',15)
subplot(2,1,2)
plot(tout,omega)
title('Angular Velocity [rad/s]','FontSize',15)
xlabel('Time [s]','FontSize',12)

figure(2)
subplot(2,2,1)
plot(real_time,cmdu)
title('Commanded Torque [Nm]','FontSize',15)
subplot(2,2,2)
plot(tout,cmdRPM)
title('Commanded RW RPM','FontSize',15)
xlabel('Time [s]','FontSize',12)
subplot(2,2,3)
plot(real_time,realu)
title('Actual Torque [Nm]','FontSize',15)
subplot(2,2,4)
plot(tout,realRPM)
title('Actual RW RPM','FontSize',15)
xlabel('Time [s]','FontSize',12)

figure(3), hold on
plot(tout,diff,'LineWidth',1)
plot(tout,0.02*ones(1,length(tout)),'k--')
plot([ts ts],[0 1],'k--')
xlabel('Time [s]','FontSize',12)

%save('workspace-test-NAME.mat')

elseif run_test == 2
%% Test 2

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides

% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'sgp4_unit_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %

%save('workspace-test-NAME.mat')
end

