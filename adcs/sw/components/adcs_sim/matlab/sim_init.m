% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all simulation parameters for 'MainSimulation.slx'. This is
% the first (and only) file that needs to be called/run to do a full
% simulation. Make sure you are at the top of the path (not in a subfolder)
%
%   Last Edited: T. Reynolds  6.23.17
% ----------------------------------------------------------------------- %

% Start fresh
clear variables; close all; clc
addpath(genpath(pwd))

% Load bus stub definitions
load('DubSat_bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
sim_params = init_sim_params(fsw_params);

% Load sim
run_time    = '10';
mdl         = 'MainSimulation';
load_system(mdl);
set_param(mdl,'StopTime', run_time);

% Simulation
sim(mdl);



