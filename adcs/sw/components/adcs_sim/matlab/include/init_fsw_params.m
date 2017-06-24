function fsw_params = init_fsw_params()

% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team

% Define all parameters to be used by FSW here. This is the first file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'.
%
%   Have one 'init_library'.m file for each FSW library. These should
%   take in fsw_params (only) and return the structs needed to run the 
%   library.
%       ex. fsw_params.control.bdot = init_bdot_controller(fsw_params);

% Last Edited: T.Reynolds 6.24.17
% ----------------------------------------------------------------------- %

% ----- Spacecraft Parameters ----- %
fsw_params.bus.inertia = [];
% --------------------------------- %

% ----- FSW parameters ----- %
fsw_params.fsw.sample_time_s = 1/10; % Sample at 10Hz
% -------------------------- %

% ----- Sensors ----- %
fsw_params.sensors  = init_sensors_fsw();
% -------------------- %

% ----- Actuators ----- %
fsw_params.actuators.magnetorquer   = init_magnetorquer_fsw();
% --------------------- %

% ----- Environment ----- %
fsw_params.environment  = init_environment_fsw();
% ----------------------- %

% ----- Controllers ----- %
fsw_params.control.bdot = init_bdot_controller( fsw_params );
fsw_params.control.pd_controller = init_pd_controller();
%fsw_params.control.momentum_unload = init_momentum_unload();
% ----------------------- %

% ----- Estimation ----- %
fsw_params.estimation.ekf   = init_ekf_estimator( sim_params );
%fsw_params.estimation.triad = init_triad_estimator();
% ---------------------- %

