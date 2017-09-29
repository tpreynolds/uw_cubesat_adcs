function [ ppt ] = init_ppt( fsw_params )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initialize all parameters for the pulsed plasma thruster.
%
%   Last Edited: T. Reynolds, 9.29.17
% ----------------------------------------------------------------------- %

ppt.t_charge    = 1.2; % time to charge in [ s ]
ppt.t_fire      = 0.002; % time it takes to "fire" [ s ]

ppt.sync_pulse     = fsw_params.bus.sync_pulse;

ppt.t_charge_pct    = ppt.t_charge/ppt.sync_pulse;



end

