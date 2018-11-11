function [ bus ] = init_bus_params()
% ----------------------------------------------------------------------- %
%INIT_BUS_PARAMS
%
%   Initializes the parameters for the physical spacecraft bus.
%
% T.Reynolds -- 2.15.18
% ----------------------------------------------------------------------- %

% Physical Parameters - for HuskySat-1
bus.mass    = 2.91084;  % [kg]
bus.dx      = 0.1;      % [m] x-axis length
bus.dy      = 0.1;      % [m] y-axis length
bus.dz      = 0.37;     % [m] z-axis length
bus.CoM     = [ -0.04952 -0.04492 0.18508 ]'; % [m] CoM location
bus.inertia = [ 0.033800072 -0.0000488358 -0.00007392968;
               -0.0000488358 0.03456792999 0.00000712402;
               -0.00007392968 0.00000712402 0.00742076536 ];
bus.prod_inertia = [ 0.0000488358; 0.00007392968; 0.00007392968 ];
bus.solar_panel_unit    = [ 0.0; 1.0; 0.0 ];

% Other parameters
bus.max_torque              = 5e-3; % [Nm]
bus.RW_RPM_thresh.max       = 10e3;
bus.RW_RPM_thresh.min       = 2e3;
bus.omega_radps_thresh.max  = 0.12;
bus.omega_radps_thresh.min  = 0.00436; % 0.25 deg/s 
bus.bstar                   = 3.2923e-5; % drag term for SGP4 from SWISSCUBE
bus.dut1                    = 0;         % SGP4 wants a UTC time
bus.point_tol               = 12;        % [deg]

end

