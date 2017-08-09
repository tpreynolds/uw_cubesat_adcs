function p_dump = init_momentum_dump( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%   Load the parameters for the momentum (p) unloading controller here. 
% Last Edited: T. Reynolds 8.8.17
% ----------------------------------------------------------------------- %

% Initial Conditions
p_dump.ic.rt_w_body_radps   = zeros(3,1);
p_dump.ic.rt_mag_body_T     = zeros(3,1);
p_dump.ic.rt_dipole_Am2     = zeros(3,1);

% Sample time
p_dump.sample_time_s    = 1/5; % sample at 5 Hz

% Momentum unloading controller gains
p_dump.gain_k     = 1;


