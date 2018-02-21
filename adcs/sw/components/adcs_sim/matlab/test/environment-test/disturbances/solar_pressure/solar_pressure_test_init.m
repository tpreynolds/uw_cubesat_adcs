%% Solar pressure unit test init file

% Test 1: 

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

% t_end   = 86400; % Sim for 1 day
t_end   = 6400;
t = [0:t_end]';

quaternionVals = [1,0,0,0]';
quaternion.time = t;
quaternion.signals.values = repmat(quaternionVals,[1 1 length(t)]);
quaternion.signals.dimensions = [4,1];

sun_vec_eciVals = [1,0,0]';
sun_vec_eci.time = t;
sun_vec_eci.signals.values = repmat(sun_vec_eciVals,[1 1 length(t)]);
sun_vec_eci.signals.dimensions = [3,1];

% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'solar_pressure_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
solar_torque = logsout.getElement('solar_torque').Values.Data;
solar_torque_time = logsout.getElement('solar_torque').Values.Time;

solar_force = logsout.getElement('solar_force').Values.Data;
solar_force_time = logsout.getElement('solar_force').Values.Time;


% ----- Plot Results ----- %

%save('workspace-disturbances-test1.mat')

