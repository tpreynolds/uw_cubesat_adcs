function soac = init_soac_params(fsw_params)
% ----------------------------------------------------------------------- %
% AACT SOCi Optimal Attitude Controller Init File
%
%   Load parameters for SOCi's constraint attitude controller (SOAC).
%   These are only parameters used in the interface library and do not
%   reflect any variables (or dimensions) used inside the library  
%
% T. Reynolds 2.28.19
% ----------------------------------------------------------------------- %

% Initial Conditions
soac.ic.sc_mode             = 0.0;
soac.ic.quat_in             = [1.0;0.0;0.0;0.0];
soac.ic.w_body_radps        = zeros(3,1);
soac.ic.hw_Nms              = zeros(3,1);
soac.ic.quat_cmd            = [1.0;0.0;0.0;0.0];
soac.ic.w_body_cmd_radps    = zeros(3,1);
soac.ic.sun_inertial_unit   = zeros(3,1);
soac.ic.gps_epoch_s         = zeros(2,1);
soac.ic.gps_time_s          = zeros(2,1);
soac.ic.cmd_torque          = zeros(3,1);
soac.ic.cmd_state           = [ soac.ic.quat_cmd; soac.ic.w_body_cmd_radps;
                                soac.ic.hw_Nms ];

% Sample time
soac.sample_time_s = (1/10); % sample at 10 Hz

% Number of discretization points
soac.N = 10;
soac.dt = 1/(soac.N-1);

% Problem sizes (must match build_SOACer.m)
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
% dimensions of cones
soac.l_dim    = 322;
soac.soc_dim  = 32;

% Parameters
soac.inertia = fsw_params.bus.inertia;

end
