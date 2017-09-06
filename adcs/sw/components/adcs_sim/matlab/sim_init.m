% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all simulation parameters for 'adcs_sim_main.slx'. This is
% the first (and only) file that needs to be called/run to do a full
% simulation. Make sure you cd is the same folder where sim_init is found
% before you run this.
%
%   Last Edited: T. Reynolds  8.3.17
% ----------------------------------------------------------------------- %

% Start fresh
clear variables; close all; clc
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_bdot/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_sim/matlab/

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);
fsw_params.bdot     = init_bdot_controller(fsw_params);

% Load sim
run_time    = '10';
mdl         = 'adcs_sim_main';
load_system(mdl);
set_param(mdl,'StopTime', run_time);

% Simulation
sim(mdl);

states = logsout.getElement('states').Values;
disturbances = logsout.getElement('disturbances').Values;
orbit_data = logsout.getElement('orbit_data').Values;
act_meas = logsout.getElement('act_meas').Values;
control = logsout.getElement('control').Values;
sens_meas = logsout.getElement('sens_meas').Values;
commands    = logsout.getElement('commands').Values;
sc_mode = logsout.getElement('sc_mode').Values;
ctrl_status    = logsout.getElement('ctrl_status').Values;
sc_in_sun    = logsout.getElement('sc_in_sun').Values;
sc_in_sun_fsw    = logsout.getElement('sc_in_sun_fsw').Values;
orbit_tle_fsw    = logsout.getElement('orbit_tle_fsw').Values;
cur_gps_time     = logsout.getElement('cur_gps_time').Values;
