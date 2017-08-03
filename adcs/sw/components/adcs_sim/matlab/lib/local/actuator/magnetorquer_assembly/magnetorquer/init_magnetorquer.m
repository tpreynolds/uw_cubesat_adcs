%% Init Sim Magnetorquer Model
%   HuskySat-1, ADCS Subsystem
% Initializes each of the magnetorquer models for use in SIM.
%   Last Update: T. Reynolds - 8.3.17

%%
function magnetorquer     = init_magnetorquer

% Start with Sim Params
magnetorquer.ic.current    = 0;
magnetorquer.permeability  = pi*4e-7;
magnetorquer.rel_perm  = 2500*magnetorquer.permeability;
magnetorquer.radius    = 0.0035;   % m
magnetorquer.length    = 0.07;     % m

magnetorquer.area_x    = pi*magnetorquer.radius^2;
magnetorquer.area_y    = pi*magnetorquer.radius^2;
magnetorquer.area_z    = 0.07*0.08;

magnetorquer.resistance_x  = 80;  % Ohms
magnetorquer.resistance_y  = 80;  % Ohms
magnetorquer.resistance_z  = 80;  % Ohms

magnetorquer.num_turns_x   = 1580;
magnetorquer.num_turns_y   = 1580;
magnetorquer.num_turns_z   = 1000;

magnetorquer.inductance_x  = magnetorquer.permeability*magnetorquer.num_turns_x^2*magnetorquer.area_x/magnetorquer.length;  % Henry
magnetorquer.inductance_y  = magnetorquer.permeability*magnetorquer.num_turns_y^2*magnetorquer.area_y/magnetorquer.length;  % Henry
magnetorquer.inductance_z  = magnetorquer.rel_perm*magnetorquer.num_turns_z^2*magnetorquer.area_z/magnetorquer.length;  % Henry

%   Compute efficiency factor                                   
magnetorquer.k_eff = mag_eff(magnetorquer.length,...
                                        magnetorquer.radius,...
                                        magnetorquer.rel_perm);

magnetorquer.mu_x     = 100;
magnetorquer.mu_y     = 100;
magnetorquer.mu_z     = 1;

magnetorquer.max_dipole = 0.25;
magnetorquer.tol        = 1e-3;
magnetorquer.max_power     = 200;  % mW
magnetorquer.max_current   = 50;   % mA
