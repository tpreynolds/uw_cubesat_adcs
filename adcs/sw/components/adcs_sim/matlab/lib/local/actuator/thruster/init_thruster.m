function thruster = init_thruster(sim_params)
% ----------------------------------------------------------------------- %
%INIT_PPT
%
% Initialize all parameters for the environment modeling contained in FSW
% Average thrust is computed with 45mN/kW with 8W to power when in
% operation. Numbers found in "Pulsed Plasma Thruster Gains in Specific Thrust for
% CubeSat Propulsion"
%
% RAIN-SAT -- T. Reynolds 7.7.18
% ----------------------------------------------------------------------- %

% Initial conditions
thruster.on             = false;
thruster.orbit_freq     = 1/3;
if( thruster.on )
    thruster.avg_thrust     = 0.36e-3;   %.36 mN of thrust on average
else
    thruster.avg_thrust     = 0.0;
end
thruster.boresight      = [ 0.0; 0.0; -1.0 ]; % point in -zB direction
thruster.pulse_duration = sim_params.telecom.sync_pulse_s;

end