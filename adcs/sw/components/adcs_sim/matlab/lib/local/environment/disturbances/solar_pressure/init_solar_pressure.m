function sol_p = init_solar_pressure(fsw_params)
% HuskySat-1, ADCS Team
%
% Initializes the solar radiation pressure torque library
%   Ref: dR-D-F, Spacecraft Dynamics & Control, 2013, pp 228-229.
%
% Last Update: S. Rice, 2.16.18

% Toggle 0/1 for turning solar pressure on/off as a disturbance torque
sol_p.on    = 0;

sol_p.force_coeff = 4.5e-6; % N/m^2

sol_p.area.a1 = fsw_params.bus.dy*fsw_params.bus.dz*[1;0;0];
sol_p.area.a2 = fsw_params.bus.dz*fsw_params.bus.dz*[0;1;0];   %one dz is actually dx with panels open
sol_p.area.a3 = fsw_params.bus.dx*fsw_params.bus.dy*[0;0;1];
sol_p.area.a4 = fsw_params.bus.dy*fsw_params.bus.dz*[-1;0;0];
sol_p.area.a5 = fsw_params.bus.dz*fsw_params.bus.dz*[0;-1;0];  %one dz is actually dx with panels open
sol_p.area.a6 = fsw_params.bus.dy*fsw_params.bus.dx*[0;0;-1];

sol_p.CoP   = fsw_params.bus.CoM;   %CoP approximated by CoM