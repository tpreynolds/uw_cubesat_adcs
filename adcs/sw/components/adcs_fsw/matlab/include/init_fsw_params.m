function fsw_params = init_fsw_params()
%INIT_FSW_PARAMS
%
% Define all parameters to be used by FSW here. This is the first file to
% be called by 'SimInit.m' to initialize simulation data for the full 'Main
% Simulation.slx'.
%
%   Have one 'init_library'.m file for each FSW library. These should
%   take in fsw_params (only) and return the structs needed to run the 
%   library. The main blocks (sensors, actuators etc.) have been set up so
%   that a call to "init_sensors" will initialize all sub-libraries used.
%       ex. fsw_params.sensors = init_sensors();
%
% RAIN-SAT -- T.Reynolds 4.18.18
fsw_params  = struct;

% ------------------------ Spacecraft Parameters ------------------------ %
fsw_params.sample_time_s    = 1/10; 
fsw_params.bus              = init_bus_params();
% ----------------------------------------------------------------------- %

% ------------------------------ Constants ------------------------------ %
fsw_params.constants    = init_fsw_constants();
% ----------------------------------------------------------------------- %

% ----------------------------- Environment ----------------------------- %
fsw_params  = init_env_estimation(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------ Update FSW Conversions with Env Data --------------- %
fsw_params  = init_time_coord_rot(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------- Sensors ------------------------------- %
fsw_params.sensor_processing    = init_sensor_processing(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------ Actuators ------------------------------ %
fsw_params.actuators    = init_actuators(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------- ADCS Mode Management ------------------------ %
fsw_params.mode_selection   = init_mode_selection(fsw_params);
fsw_params.target_gen       = init_target_generation(fsw_params);
% ----------------------------------------------------------------------- %

% ----------------------------- Controllers ----------------------------- %
fsw_params.control.pd_controller    = init_pd_controller(fsw_params);
fsw_params.control.p_dump           = init_momentum_dump(fsw_params);
fsw_params.control.cmd_processing   = init_cmd_processing(fsw_params);
fsw_params.control.sun_point        = init_sun_point(fsw_params);
% ----------------------------------------------------------------------- %

% ----------------------- Ground Station Prediction --------------------- %
fsw_params.gs_prediction    = init_gs_prediction(fsw_params);
% ----------------------------------------------------------------------- %

% ------------------------------ Estimation ----------------------------- %
% EKF initialized in sim_params.
% ----------------------------------------------------------------------- %

