function PPT = init_PPT(sim_params)
% ----------------------------------------------------------------------- %
%INIT_PPT
%
% Initialize all parameters for the environment modeling contained in FSW
% Average thrust is computed with 45mN/kW with 8W to power when in
% operation. Numbers found in "Pulsed Plasma Thruster Gains in Specific Thrust for
% CubeSat Propulsion"
%
% S. Rice 4.30.18
% ----------------------------------------------------------------------- %

% Initial conditions
PPT.on              = 1;
PPT.orbit_freq      = 1/3;
PPT.avg_thrust      = 0.36e-3;   %.36 mN of thrust on average
PPT.pulse_duration  = sim_params.CAN.sync_pulse_period_s;

end