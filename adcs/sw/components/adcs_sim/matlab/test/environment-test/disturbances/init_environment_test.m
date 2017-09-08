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
orb     = tle2orb(fsw_params.bus.orbit_tle);
[reci,veci] = orb2eci(orb);
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
t_end   = 5400;
sim_params.dynamics.ic.rate_init = [0.2; -0.2; 0.2];

% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'environment_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
orbit_data = logsout.getElement('orbit_data').Values;
states  = logsout.getElement('states').Values;
disturbances = logsout.getElement('disturbances').Values;
% ----- End Analysis ----- %

%save('workspace-disturbances-test1.mat')

