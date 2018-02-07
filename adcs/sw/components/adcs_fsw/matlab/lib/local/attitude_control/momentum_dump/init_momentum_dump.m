function p_dump = init_momentum_dump(fsw_params)
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%   Load the parameters for the momentum (p) unloading controller here. 
% Last Edited: E. Hansen 01.05.18
% ----------------------------------------------------------------------- %

% Initial Conditions
p_dump.ic.rt_w_body_radps   = zeros(3,1);
p_dump.ic.rt_mag_body_T     = zeros(3,1);
p_dump.ic.rt_dipole_Am2     = zeros(3,1);
p_dump.ic.rt_PPT_on         = 0;
p_dump.ic.rt_B_meas_valid   = 0;
p_dump.ic.delay             = zeros(3,1);
p_dump.ic.ang_mom_ref       = fsw_params.actuators.reaction_wheel.inertia_matrix*[1000*fsw_params.convert.RPM_2_RADPS;...
                                                     1000*fsw_params.convert.RPM_2_RADPS;...
                                                     1000*fsw_params.convert.RPM_2_RADPS]; %reference angular momentum of reaction wheels

% Sample time
p_dump.sample_time_s    = 1/5; % sample at 5 Hz

% Momentum unloading controller gains
p_dump.gain_k     = 5*10^(-2);
