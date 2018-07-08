function fsw_params = init_env_estimation(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_ENV_ESTIMATION
%
% INIT_ENV_ESTIMATION(fsw_params) Initializes all parameters for the 
% environment models contained in FSW.
%
% RAIN-SAT -- T. Reynolds 7.7.18
% ----------------------------------------------------------------------- %

% Library Sample Time
env_estimation.sample_time_s    = fsw_params.sample_time_s;

% Initialize SGP4 library
env_estimation.orb_estimation   = ....
                            init_orb_estimation(fsw_params,env_estimation);

% Rate Transition Initial Conditions
env_estimation.ic.gps_time      = ...
                            env_estimation.orb_estimation.sgp4.gps_time;
env_estimation.ic.orbit_tle     = ...
                            env_estimation.orb_estimation.sgp4.orbit_tle;                        
                        
% Initialze ground station prediction
env_estimation.gs_estimation    = init_gs_prediction(env_estimation);

% Initialize sun vector library
env_estimation.sun_estimation   = ...
                            init_sun_estimation(fsw_params,env_estimation);

% Initialize magnetic field library
env_estimation.mag_vec      = init_magnetic_field();

% Update fsw_params struct
fsw_params.env_estimation   = env_estimation;
fsw_params.bus.orbit_tle    = env_estimation.orb_estimation.sgp4.orbit_tle;

% Update constant struct
fsw_params.constants.mag.orbit_freq = ...
                      env_estimation.orb_estimation.sgp4.orbit_tle(9) * ...
                      fsw_params.constants.convert.rev2rad * ...
                      fsw_params.constants.time.sec2day;

end