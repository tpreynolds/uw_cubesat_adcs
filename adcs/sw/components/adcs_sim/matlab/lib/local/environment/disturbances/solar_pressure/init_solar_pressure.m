function sol_p = init_solar_pressure
% HuskySat-1, ADCS Team
%
% Initializes the solar radiation pressure torque library
%   Ref: dR-D-F, Spacecraft Dynamics & Control, 2013, pp 228-229.
%
% Last Update: T. Reynolds, 8.3.17

sol_p.force_coeff = 4.5e-6; % N/m^2

sol_p.area.a1 = .10*.30*[1;0;0];
sol_p.area.a2 = .30*.30*[0;1;0];
sol_p.area.a3 = .10*.10*[0;0;1];
sol_p.area.a4 = .10*.30*[-1;0;0];
sol_p.area.a5 = .30*.30*[0;-1;0];
sol_p.area.a6 = .10*.10*[0;0;-1];

sol_p.CoP   = [0.05 0.05 0.15]';