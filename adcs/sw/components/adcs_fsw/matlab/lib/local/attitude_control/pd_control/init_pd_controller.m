function pd_controller = init_pd_controller( fsw_params )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%   Load the parameters for the PD reorientation controller. Any block used
%   in the controller should be initialized here. 
% Last Edited: T. Reynolds 11.12.17
% ----------------------------------------------------------------------- %

% Initial Conditions
pd_controller.ic.rt_quat_in     = zeros(4,1);
pd_controller.ic.rt_w_body_radps    = zeros(3,1);
pd_controller.ic.rt_command_torque  = zeros(3,1);
pd_controller.ic.rt_command_RPM     = zeros(3,1);
pd_controller.ic.torque     = zeros(3,1);

% Sample time
pd_controller.sample_time_s     = 1/10; % sample at 10 Hz

% Conversions
pd_controller.rps_2_rpm     = 60/(2*pi);

J  = fsw_params.bus.inertia;

% Choose damping ratio and natural frequency
z   = 1; % Critically damped
wn  = 0.01*2*pi; % Small natural frequency

pd_controller.p_gain  = -wn^2.*J;
pd_controller.d_gain  = -2*wn*z.*J;

% PD Controller gains - TUNED IN TEST FILE
% pd_controller.p_gain = -0.001114238870515;
% pd_controller.d_gain = -0.008423250000000;

end


