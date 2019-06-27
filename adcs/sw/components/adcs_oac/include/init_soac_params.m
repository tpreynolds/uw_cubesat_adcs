function soac = init_soac_params(fsw_params)
%INIT_SOAC_PARAMS   AACT SOCi Optimal Attitude Controller Init File
%
% Syntax: soac = init_soac_params(fsw_params)
%
%  Load parameters for SOCi's constraint attitude controller (SOAC).
%  These are both parameters used in the interface library and variables
%  (or dimensions) used inside the library. The output struct soac is used
%  as an input (of type parameter) to both the SOAC_INIT and SOAC_SOLVE
%  functions of the library.
%
%  The build configuration reflects the constraints that are imposed, and
%  any changes to its value must be followed by re-running build_SOAC.m
%  from the `adcs_oac/build/` directory.
%
% T. Reynolds -- RAIN Lab

% Initial Conditions
soac.ic.sc_mode             = 0.0;
soac.ic.quat_in             = [1;0;0;0];
soac.ic.w_body_radps        = zeros(3,1);
soac.ic.hw_Nms              = zeros(3,1);
soac.ic.quat_cmd            = [0.86603;0.28868;0.28868;0.28868];
soac.ic.w_body_cmd_radps    = zeros(3,1);
soac.ic.sun_inertial_unit   = zeros(3,1);
soac.ic.gps_epoch_s         = zeros(2,1);
soac.ic.gps_time_s          = zeros(2,1);
soac.ic.cmd_torque          = zeros(3,1);
soac.ic.cmd_state           = [ soac.ic.quat_cmd; soac.ic.w_body_cmd_radps;
                                soac.ic.hw_Nms ];

% SOAC configuration
soac.config = 'bie'; % b = baseline, bi = b+inclusion, bie = bi+exclusion
                            
% Number of discretization points
soac.N  = 10;
soac.dt = 1/(soac.N-1);

% defined configuration dependent parameters
switch soac.config
    case 'b'
        soac.sample_time_s = (1/10); % sample time [s]
        % problem sizes (must match build_soac.m)
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
    case 'bi'
        soac.sample_time_s = (1/10); % sample time [s]
        % problem sizes (must match build_soac.m)
        soac.c_size   = 332;
        soac.Air_size = 1278;
        soac.Ajc_size = 333;
        soac.Apr_size = 1278;
        soac.b_size   = 117;
        soac.Gir_size = 754;
        soac.Gjc_size = 333;
        soac.Gpr_size = 754;
        soac.h_size   = 414;
        soac.q_size   = 11;
        soac.y_size   = 334;
        % dimensions of cones
        soac.l_dim    = 322;
        soac.soc_dim  = [32;6;6;6;6;6;6;6;6;6;6];
    case 'bie'
        soac.sample_time_s = (1/2); % sample time [s]
        % problem sizes (must match build_soac.m)
        soac.c_size   = 332;
        soac.Air_size = 1278;
        soac.Ajc_size = 333;
        soac.Apr_size = 1278;
        soac.b_size   = 117;
        soac.Gir_size = 834;
        soac.Gjc_size = 333;
        soac.Gpr_size = 834;
        soac.h_size   = 474;
        soac.q_size   = 21;
        soac.y_size   = 334;
        % dimensions of cones
        soac.l_dim    = 322;
        soac.soc_dim  = [32;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6;6];
    otherwise
        error('INIT_SOAC: undefined configuration')
end

% Parameters
soac.inertia = fsw_params.bus.inertia;
soac.w_max  = 0.1;
soac.T_max  = 3.2e-3;
soac.s_min  = 15;
soac.s_max  = 25;
soac.w_v    = 1e2;

end
