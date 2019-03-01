function gnc2 = init_gnc2( )
% ----------------------------------------------------------------------- %
% AACT SOCi
%
%   Load parameters for SOCi's constraint attitude controller (SOACer).
%   These are only parameters used in the interface library and do not
%   reflect any variables (or dimensions) used inside the library  
%
% T. Reynolds 2.28.19
% ----------------------------------------------------------------------- %

% Initial Conditions
gnc2.ic.sc_mode             = 0.0;
gnc2.ic.quat_in             = zeros(4,1);
gnc2.ic.w_body_radps        = zeros(3,1);
gnc2.ic.quat_cmd            = zeros(4,1);
gnc2.ic.w_body_cmd_radps    = zeros(3,1);
gnc2.ic.sun_inertial_unit   = zeros(3,1);
gnc2.ic.gps_epoch_s         = zeros(2,1);
gnc2.ic.gps_time_s          = zeros(2,1);
gnc2.ic.cmd_torque          = zeros(3,1);

% Sample time
gnc2.sample_time_s = 1; % sample at 1 Hz


end
