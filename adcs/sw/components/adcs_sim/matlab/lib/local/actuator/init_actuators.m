function actuators = init_actuators( fsw_params )
% ----------------------------------------------------------------------- %
%INIT_ACTUATORS
%
% Initialize all parameters for the reaction wheel assembly model in SIM.
%
% RAIN-SAT -- T. Reynolds 7.7.18
% ----------------------------------------------------------------------- %

% Initial conditions
actuators.ic.MT_power_OK    = 0;
actuators.ic.MT_on          = 0;
actuators.ic.RW_power_W     = zeros(3,1);
actuators.ic.MT_power_mW    = zeros(3,1);
actuators.ic.RW_RPM         = zeros(3,1);
actuators.ic.RW_omega_radps = zeros(3,1);

% PCT of SyncPulse that belongs to actuation. Assumes first x% of SyncPulse
actuators.pct_sync_pulse    = 60;

% Actuator assemblies
actuators.magnetorquer      = init_magnetorquer(fsw_params);
actuators.reaction_wheel    = init_reaction_wheel_assembly();

end