function actuators = init_actuators( varargin )
% ----------------------------------------------------------------------- %
%INIT_ACTUATORS
%
% Initialize all parameters for the reaction wheel assembly model in SIM.
%
% T. Reynolds -- 8.3.17
% ----------------------------------------------------------------------- %

% Initial conditions
actuators.ic.MT_power_OK    = 0;
actuators.ic.MT_on          = 0;
actuators.ic.RW_power_W     = zeros(3,1);
actuators.ic.MT_power_mW    = zeros(3,1);
actuators.ic.RW_RPM         = zeros(3,1);
actuators.ic.RW_omega_radps = zeros(3,1);

% Actuator assemblies
actuators.magnetorquer      = init_magnetorquer_assembly();
actuators.reaction_wheel    = init_reaction_wheel_assembly();
if( nargin == 1 )
    actuators.ppt           = init_ppt(varargin{1});
end

end