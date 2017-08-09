 function [sim_params,fsw_params] = init_sim_params(fsw_params)

% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team

% Define all parameters to be used by SIM here. This is the second file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'. 
%   Takes in already defined fsw_params so that sim values can be defined
%   using the fsw values

% Last Edited: T.Reynolds 6.23.17
% ----------------------------------------------------------------------- %

% ----- Spacecraft Parameters ----- %
% Geometry
sim_params.sc.mass  = 4.5;  % [kg] Satellite mass
sim_params.sc.dx = 0.11;                  % [m] X-axis length
sim_params.sc.dy = 0.1;                   % [m] Y-axis length
sim_params.sc.dz = 0.3;                   % [m] Z-axis length
sim_params.sc.center_of_mass = [0.03 0.01 -0.02]';     % [m] CoM location 

% Moments of inertia (cuboid approximation)
Ix = (sim_params.sc.mass/12)*(sim_params.sc.dy^2+sim_params.sc.dz^2);    % X-axis inertia
Iy = (sim_params.sc.mass/12)*(sim_params.sc.dx^2+sim_params.sc.dz^2);    % Y-axis inertia
Iz = (sim_params.sc.mass/12)*(sim_params.sc.dx^2+sim_params.sc.dy^2);    % Z-axis inertia
sim_params.bus.inertia = diag([Ix Iy Iz]);
% -----

% ----- Dynamics -----%
sim_params.dynamics = init_dynamics;
% -----

% ----- Sensors ----- %
% Magnetometer
sim_params.sensors  = init_sensors();
% -----

% ----- Actuators ----- %
sim_params.actuators    = init_actuators();
% -----

% ----- Environment ----- %
sim_params.environment  = init_environment();
% -----

% ----- SGP4 - Orbit Propagator ----- %
fsw_params.bus.orbit_tle = sim_params.environment.sgp4.orbit_tle;
% -----

% ----- Estimation ----- %
fsw_params.estimation   = init_extended_kalman_filter(sim_params);
% -----


% END Function  --------------------------------------------------------- %
