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
% --------------------------------- %

% ----- Parameters ----- %
fsw_params.sample_time_s = 1/10; % Sample at 10Hz
% -------------------------- %

% ----- Sensors ----- %
fsw_params.sensors  = init_sensors();
% -------------------- %

% ----- Actuators ----- %
fsw_params.actuators    = init_actuators();
% --------------------- %

% ----- Environment ----- %
fsw_params.environment  = init_environment();
% ----------------------- %

% ----- Controllers ----- %
% Included in FSW
% ----------------------- %

% ----- Estimation ----- %
% Included in FSW
% ---------------------- %

