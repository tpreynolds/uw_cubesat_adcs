function fsw_params = init_fsw_params()

% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team

% Define all parameters to be used by FSW here. This is the first file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'.
%
%   Have one 'init_library'.m file for each FSW library. These should
%   take in fsw_params (only) and return the structs needed to run the 
%   library. The main blocks (sensors, actuators etc.) have been set up so
%   that a call to "init_sensors" will initialize all sub-libraries used.
%       ex. fsw_params.sensors = init_sensors();

% Last Edited: T.Reynolds 11.16.17
% ----------------------------------------------------------------------- %

% ----- Spacecraft Parameters ----- %
% Geometry
fsw_params.sc.mass  = 4.5;  % [kg] Satellite mass
fsw_params.sc.dx = 0.11;                  % [m] X-axis length
fsw_params.sc.dy = 0.1;                   % [m] Y-axis length
fsw_params.sc.dz = 0.3;                   % [m] Z-axis length
fsw_params.sc.center_of_mass = [0.03 0.01 -0.02]';     % [m] CoM location
% Moments of inertia (cuboid approximation)
Ix = (fsw_params.sc.mass/12)*(fsw_params.sc.dy^2+fsw_params.sc.dz^2);    % X-axis inertia
Iy = (fsw_params.sc.mass/12)*(fsw_params.sc.dx^2+fsw_params.sc.dz^2);    % Y-axis inertia
Iz = (fsw_params.sc.mass/12)*(fsw_params.sc.dx^2+fsw_params.sc.dy^2);    % Z-axis inertia
fsw_params.sc.inertia   = diag([Ix Iy Iz]);
fsw_params.bus.inertia  = fsw_params.sc.inertia;
fsw_params.bus.quat_id   = [1 0 0 0]';
fsw_params.bus.RW_RPM_thresh    = [2e3 10e3]; % RPM
fsw_params.bus.omega_radps_thresh     = [0.001 0.12]; % [rad/s]
fsw_params.bus.bstar    = 3.2923e-5; % taken from SWISSCUBE
fsw_params.bus.sync_pulse   = 2; % minor sync pulse for duty cycling PPT and info dump
% --------------------------------- %

% ----- Parameters ----- %
fsw_params.sample_time_s    = 1/10; % Sample at 10Hz
fsw_params.convert.KM2M     = 1e3; % convert km to m
fsw_params.convert.M2KM     = 1e-3;  % convert m to km
fsw_params.convert.NT2T     = 1e-9;  % convert nano-Tesla to Tesla
fsw_params.convert.RPM_2_RADPS  = (pi/30); % convert RPM to rad/s
% -------------------------- %

% ----- Sensors ----- %
fsw_params.sensors              = init_sensors();
fsw_params.sensor_processing    = init_sensor_processing();
% -------------------- %

% ----- Actuators ----- %
fsw_params.actuators    = init_actuators();
% --------------------- %

% ----- Environment ----- %
fsw_params.environment  = init_environment();
% ----------------------- %

% ----- Controllers ----- %
fsw_params.control.pd_controller    = init_pd_controller(fsw_params);
fsw_params.control.p_dump           = init_momentum_dump();
% ----------------------- %

% ----- Estimation ----- %

% ---------------------- %

