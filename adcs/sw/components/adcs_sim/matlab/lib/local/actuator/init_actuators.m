function actuators = init_actuators( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initialize all parameters for the reaction wheel assembly model in SIM.
%
%   Last Edited: T. Reynolds, 8.3.17
% ----------------------------------------------------------------------- %

% Initial conditions
actuators.magnetorquer = init_magnetorquer_assembly();
actuators.reaction_wheel    = init_reaction_wheel_assembly();


end