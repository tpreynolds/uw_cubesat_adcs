 function [sim_params,fsw_params] = init_sim_params(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_SIM_PARAMS
%
% Define all parameters to be used by SIM here. This is the second file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'. 
%   Takes in already defined fsw_params so that sim values can be defined
%   using the fsw values
%
% T. Reynolds -- 4.18.18
% ----------------------------------------------------------------------- %---------------------------------------------- %

% ----- Spacecraft Parameters ----- %
sim_params.bus                  = fsw_params.bus;
[sim_params.MET, fsw_params]    = init_MET(fsw_params);
% --------------------------------- %

% ----- Physical Bus Signal Emulators ----- %
[sim_params.CAN, fsw_params]  = init_CAN(sim_params, fsw_params);
% ----------------------------------------- %

% ----- Dynamics ----- %
[sim_params.dynamics, fsw_params] = init_dynamics(fsw_params);
% -------------------- %

% ----- Sensors ----- %
sim_params.sensors  = init_sensors(fsw_params);
% ------------------- %

% ----- Actuators ----- %
sim_params.actuators    = init_actuators(sim_params);
% --------------------- %

% ----- Environment ----- %
sim_params  = init_environment_sim(fsw_params,sim_params);
% ----------------------- %

% ----- Estimation ----- %
fsw_params.estimation   = init_extended_kalman_filter(sim_params);
% ---------------------- %

 end