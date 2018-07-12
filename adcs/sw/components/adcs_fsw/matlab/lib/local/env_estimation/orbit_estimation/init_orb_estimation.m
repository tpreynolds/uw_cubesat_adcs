function orb_estimation = init_orb_estimation( fsw_params,env_estimation )
% ----------------------------------------------------------------------- %
%INIT_ORB_ESTIMATION
%
% INIT_ORB_ESTIMATION(fsw_params,env_estimation) Initializes all parameters
% for FSW's orbital estimation routines.
%
% RAIN-SAT -- T. Reynolds 7.7.18
% ----------------------------------------------------------------------- %

% Sample time
orb_estimation.sample_time_s    = env_estimation.sample_time_s;

% SGP4
orb_estimation.sgp4             = init_sgp4(fsw_params);

% Initial conditions not in other structs
orb_estimation.ic.JD_J2000_utc  = orb_estimation.sgp4.orbit_tle(2) - ...
                                    fsw_params.constants.time.JD_J2000;                               

end