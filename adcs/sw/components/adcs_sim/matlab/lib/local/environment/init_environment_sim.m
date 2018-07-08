function sim_params = init_environment_sim(fsw_params,sim_params)
% ----------------------------------------------------------------------- %
%INIT_ENVIRONMENT_SIM
%
%   Initializes the whole environment block used in SIM.
%
% T. Reynolds -- 8.10.17
% ----------------------------------------------------------------------- %

% Initialize all sub blocks
sim_params.environment.sol_p       = init_solar_pressure(fsw_params);
sim_params.environment.aero_drag   = init_aero_drag();
sim_params.environment.gravity     = init_gravity_field();
sim_params.environment.magnetic    = init_magnetic_field();

sim_params.environment.sgp4        = init_sgp4(fsw_params);
sim_params.environment.ppt         = init_ppt(sim_params);

% Update constant struct
sim_params.constants.mag.orbit_freq = ...
                                sim_params.environment.sgp4.orbit_tle(9) * ...
                                fsw_params.constants.convert.rev2rad * ...
                                fsw_params.constants.time.sec2day;



end
