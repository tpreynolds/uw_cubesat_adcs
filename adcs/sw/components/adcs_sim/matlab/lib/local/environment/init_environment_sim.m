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

sim_params.environment.sgp4        = fsw_params.env_estimation.orb_estimation.sgp4;
sim_params.environment.thruster    = init_thruster(sim_params);

% Update constant struct
sim_params.constants.mag.orbit_freq = ...
                                sim_params.environment.sgp4.orbit_tle(9) * ...
                                fsw_params.constants.convert.rev2rad * ...
                                fsw_params.constants.time.sec2day;

sim_params.constants.ic.orbit_data  = [ zeros(3,1);
                                        sim_params.environment.magnetic.ic.eci_T;
                                        zeros(9,1);
                                        fsw_params.constants.ic.time.gps ];
sim_params.constants.ic.env_acc_eci_mps2 = zeros(3,1);
sim_params.constants.ic.mag_eci_T   = sim_params.environment.magnetic.ic.eci_T;
sim_params.constants.ic.sun_eci     = zeros(3,1);

end
