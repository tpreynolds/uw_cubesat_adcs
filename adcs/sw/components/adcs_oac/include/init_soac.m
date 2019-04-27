function soac = init_soac( )
% ----------------------------------------------------------------------- %
% AACT SOCi
%
%   Load parameters for SOCi's constraint attitude controller (SOAC).
%   These are only parameters used in the interface library and do not
%   reflect any variables (or dimensions) used inside the library  
%
% T. Reynolds 2.28.19
% ----------------------------------------------------------------------- %

% Initial Conditions
soac.ic.sc_mode             = 0.0;
soac.ic.quat_in             = zeros(4,1);
soac.ic.w_body_radps        = zeros(3,1);
soac.ic.quat_cmd            = zeros(4,1);
soac.ic.w_body_cmd_radps    = zeros(3,1);
soac.ic.sun_inertial_unit   = zeros(3,1);
soac.ic.gps_epoch_s         = zeros(2,1);
soac.ic.gps_time_s          = zeros(2,1);
soac.ic.cmd_torque          = zeros(3,1);

% Sample time
soac.sample_time_s = 1; % sample at 1 Hz

% Number of discretization points
soac.N = 10;
soac.dt = 1/(soac.N-1);

% Problem sizes (must match init_SOACer.m)
% soac.c_size      = 241;
% soac.Air_size    = 921;
% soac.Ajc_size    = 242;
% soac.Apr_size    = 921;
% soac.b_size      = 84;
% soac.Gir_size    = 402;
% soac.Gjc_size    = 242;
% soac.Gpr_size    = 402;
% soac.h_size      = 262;
% soac.q_size      = 1;
% soac.y_size      = 243;

soac.c_size   = 332;
soac.Air_size = 1278;
soac.Ajc_size = 333;
soac.Apr_size = 1278;
soac.b_size   = 117;
soac.Gir_size = 674;
soac.Gjc_size = 333;
soac.Gpr_size = 674;
soac.h_size   = 354;
soac.q_size   = 1;
soac.y_size   = 334;

end
