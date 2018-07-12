%% Sunsensor sensor processing unit test init file

% Run the test in the Simulink file and look at the scopes.

% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 12.12.17
%% Load paths

% Start fresh
clear variables; close all; clc
set(0,'defaulttextinterpreter','latex');
addpath(genpath('../../../../matlab/')) % adds the fsw libs
addpath(genpath('../../../../../adcs_sim/matlab/')) % add the sim libs

% Load bus stub definitions
load('bus_definitions.mat')

%% Test

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
t_end   = 100;
% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'sunsensor_processing_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %


