%% Init Sim Magnetorquer Model
%   HuskySat-1, ADCS Subsystem
%   Initializes parameters for the aero_drag library. No parameters current 
%    required, so this is an empty struct.
%
%   Last Update: T. Reynolds - 2.13.18

%%
function aero    = init_aero_drag

% Initialize empty struct
aero    = struct();
% Toggle on/off to allow aerodynamic drag as a disturbance torque
aero.on     = 0;

