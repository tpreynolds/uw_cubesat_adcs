%% Disturbances unit test init file


% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 8.31.17
%% Load paths

clear variables; close all; clc;
set(0,'defaulttextinterpreter','latex');

% Start fresh
clear variables; close all; clc
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_sim/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_sim/matlab/test/


%% Test 1

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
sgp4.tle_filename = 'SWISSCUBE.tle'; % the right TLE
[sgp4.orbit_tle,sgp4.JD_epoch_days] = get_tle(sgp4.tle_filename);
fsw_params.bus.orbit_tle = sgp4.orbit_tle;
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
t_end   = 5400;
sim_params.dynamics.ic.rate_init = [0; 0; 0];

% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'disturbances_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
dt_aero = logsout.getElement('dt_aero').Values.Data;
dt_aero_time = logsout.getElement('dt_aero').Values.Time;

dt_grav = logsout.getElement('dt_grav').Values.Data;
dt_grav_time = logsout.getElement('dt_grav').Values.Time;

dt_solar = logsout.getElement('dt_solar').Values.Data;
dt_solar_time = logsout.getElement('dt_solar').Values.Time;

env_acc_eci = logsout.getElement('env_acc_eci').Values.Data;
env_acc_eci_time = logsout.getElement('env_acc_eci').Values.Time;

mag_vector_eci = logsout.getElement('mag_vector_eci').Values.Data;
mag_vector_eci_time = logsout.getElement('mag_vector_eci').Values.Time;

sun_vec_eci = logsout.getElement('sun_vec_eci').Values.Data;
sun_vec_eci_time = logsout.getElement('sun_vec_eci').Values.Time;
% ----- End Analysis ----- %

%save('workspace-disturbances-test1.mat')

