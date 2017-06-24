function magnetorquer     = init_magnetorquer_fsw( )
% ----------------------------------------------------------------------- %
% Magnetorquer FSW Init File
%   UW HuskySat-1, ADCS Team
%   Last Edited: T. Reynolds 6.23.17

% Data taken from "Magnetorquer_desgin_V2(3).pdf" 
%   on CubeSat wiki
% ----------------------------------------------------------------------- %

%   Initial Condtions
magnetorquer.ic.rt_in      = [0 0 0]';
magnetorquer.ic.rt_out     = [0 0 0]';
magnetorquer.sample_time_s     = 0.1;

% Torque rod characteristics
magnetorquer.permeability  = pi*4e-7;
magnetorquer.radius    = 0.0035;   % m
magnetorquer.length    = 0.07;     % m
magnetorquer.rel_perm  = 2500*magnetorquer.permeability;

magnetorquer.resistance_x  = 80;  % Ohms
magnetorquer.resistance_y  = 80;  % Ohms
magnetorquer.resistance_z  = 80;  % Ohms

magnetorquer.num_turns_x   = 1580;
magnetorquer.num_turns_y   = 1580;
magnetorquer.num_turns_z   = 1000;

magnetorquer.area_x    = pi*magnetorquer.radius^2;
magnetorquer.area_y    = pi*magnetorquer.radius^2;
magnetorquer.area_z    = 0.07*0.08;

% Compute efficiency factor
magnetorquer.k_eff = mag_eff(magnetorquer.length,... 
                                        magnetorquer.radius,...
                                        magnetorquer.rel_perm);
% Ferrocore gains
magnetorquer.gain_x        = 100;
magnetorquer.gain_y        = 100;

% Performance capabilities
magnetorquer.max_dipole    = 0.25;
magnetorquer.max_rate      = 10000;
magnetorquer.dig_val       = 255;
magnetorquer.dv_2_m        = magnetorquer.max_dipole/magnetorquer.dig_val;
magnetorquer.m_2_dv        = 1/magnetorquer.dv_2_m;

%   Duty Cycle
magnetorquer.duty_cycle_period_s   = 1; 
magnetorquer.pct_duty_cycle_on     = 50;

% Bias
magnetorquer.bias   = [0 0 0]';

% 