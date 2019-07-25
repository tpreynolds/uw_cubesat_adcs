% ----------------------------------------------------------------------- %
%SIM_INIT   Initialize the RAIN-SAT Simulator
%
% Initializes all simulation parameters for 'adcs_sim_main.slx'. This is
% the first (and only) file that needs to be called/run to do a full
% simulation. Make sure your cd is the same folder where sim_init is found
% before you run this.
%
% T. Reynolds -- 1.29.18
% ----------------------------------------------------------------------- %

% Start fresh
clear variables; close all; clc
addpath(genpath(pwd))
addpath(genpath('../../adcs_fsw/matlab/'))
addpath(genpath('../../adcs_oac/'))

% Load bus stub definitions
load('bus_definitions.mat')
load('bus_definitions_fsw.mat')

% Load parameters for both flight software and simulation
TLE = 'equisat_TLE.txt';
[fsw_params,soac_params] = init_fsw_params(TLE);
[sim_params,fsw_params]  = init_sim_params(fsw_params);

% Load sim and set params
run_time    = 5400;
mdl         = 'adcs_sim_main';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));