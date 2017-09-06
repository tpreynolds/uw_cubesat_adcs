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

% Last Edited: T.Reynolds 8.3.17
% ----------------------------------------------------------------------- %

% ----- Spacecraft Parameters ----- %
fsw_params.bus.inertia = [];
fsw_params.bus.quat_commanded   = [1 0 0 0]';
fsw_params.bus.RW_RPM_thresh    = 16e3; % RPM
fsw_params.bus.omega_radps_thresh     = 0.12; % [rad/s]
fsw_params.bus.bstar    = 3.2923e-5; % taken from SWISSCUBE
% --------------------------------- %

% ----- Parameters ----- %
fsw_params.sample_time_s = 1/10; % Sample at 10Hz
fsw_params.convert.KM2M             = 1e3; % convert km to m
fsw_params.convert.M2KM             = 1e-3;  % convert m to km
fsw_params.convert.NT2T     = 1e-9;  % convert nano-Tesla to Tesla
% -------------------------- %

% ----- Sensors ----- %
fsw_params.sensors  = init_sensors();
fsw_params.sensor_processing    = init_sensor_processing();
% -------------------- %

% ----- Actuators ----- %
fsw_params.actuators    = init_actuators();
% --------------------- %

% ----- Environment ----- %
fsw_params.environment  = init_environment();
% ----------------------- %

% ----- Controllers ----- %
fsw_params.control.pd_controller    = init_pd_controller();
fsw_params.control.p_dump   = init_momentum_dump();
% ----------------------- %

% ----- Estimation ----- %

% ---------------------- %

