 function [sim_params,fsw_params] = init_sim_params(fsw_params)
%INIT_SIM_PARAMS
%
% INIT_SIM_PARAMS(fsw_params)
% Defines all parameters to be used by SIM. This is the second file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'. 
%   Takes in already defined fsw_params so that sim values can be defined
%   using the fsw values
%
% Outputs both newly defined sim_params and updated fsw_params struct
%
% RAIN-SAT -- T. Reynolds 4.18.18

sim_params.sample_time_s    = (1/100);

% ------------------------ Spacecraft Parameters ------------------------ %
sim_params.bus                  = fsw_params.bus;
[sim_params.MET, fsw_params]    = init_MET(fsw_params);
% ----------------------------------------------------------------------- %

% -------------------- Physical Bus Signal Emulators -------------------- %
[sim_params.telecom, fsw_params]  = init_telecom(sim_params, fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------ Dynamics ------------------------------- %
[sim_params.dynamics, fsw_params] = init_dynamics(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------- Sensors ------------------------------- %
sim_params.sensors  = init_sensors(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------ Actuators ------------------------------ %
sim_params.actuators            = fsw_params.actuators;
sim_params.actuators.thruster   =  init_thruster(sim_params);
% ----------------------------------------------------------------------- %

% ----------------------------- Environment ----------------------------- %
sim_params  = init_environment_sim(fsw_params,sim_params);
% ----------------------------------------------------------------------- %

% ----------------------------- Estimation ------------------------------ %
fsw_params.estimation   = init_extended_kalman_filter(sim_params);
% ----------------------------------------------------------------------- %

 end