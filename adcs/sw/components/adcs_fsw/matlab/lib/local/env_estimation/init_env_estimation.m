function env_estimation = init_env_estimation(fsw_params)
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initialize all parameters for the environment modeling contained in FSW
%
%   Last Edited: T. Reynolds 2.17.18
% ----------------------------------------------------------------------- %

% Library Sample Time
env_estimation.sample_time_s    = fsw_params.sample_time_s;

% Rate Transition Initial Conditions
env_estimation.ic.gps_time      = fsw_params.environment.sgp4.ic.gps_time;
env_estimation.ic.orbit_tle     = fsw_params.environment.sgp4.orbit_tle;


end