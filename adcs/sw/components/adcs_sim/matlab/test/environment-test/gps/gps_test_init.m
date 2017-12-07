%% GPS unit test init file

% Test 1: Set the initial GPS week to 1 and seconds into that week as 1.
% Run the test for about 2 weeks of simulated time to make sure the
% roll-overs work correctly.

% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 12.5.17
%% Load paths and stuff needed
clear variables;

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);
fsw_params.bdot     = init_bdot_controller(fsw_params);



%% Test 1

% Overrides
%sim_params.environment.sgp4.gps_sec_init = 0;
%sim_params.environment.sgp4.gps_week_init = 1;
% -----

t_end   = 86400*15; % Sim for 15 days to get 2 roll-overs

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'gps_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
time_gps = logsout.getElement('time_gps').Values.Data;
time_gps_time = logsout.getElement('time_gps').Values.Time;


%% ----- Plot Results ----- %
figure(1)
subplot(2,1,1), hold on
stairs(time_gps_time,time_gps(:,1),'linewidth',1)
xlabel('Time [s]')
title('Simulated GPS Seconds into Week')
subplot(2,1,2), hold on
stairs(time_gps_time,time_gps(:,2),'LineWidth',1)
xlabel('Time [s]')
title('Simulated GPS Weeks')

%save('workspace-disturbances-test1.mat')

