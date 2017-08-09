function pd_controller = init_pd_controller( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%   Load the parameters for the PD reorientation controller. Any block used
%   in the controller should be initialized here. 
% Last Edited: T. Reynolds 8.8.17
% ----------------------------------------------------------------------- %

% Initial Conditions
pd_controller.ic.rt_quat_in     = zeros(4,1);
pd_controller.ic.rt_w_body_radps    = zeros(3,1);
pd_controller.ic.rt_command_torque  = zeros(3,1);
pd_controller.ic.rt_command_RPM     = zeros(3,1);

% Sample time
pd_controller.sample_time_s     = 1/10; % sample at 10 Hz

% Conversions
pd_controller.pwr_const     = 9548.8;

% PD Controller gains
pd_controller.p_gain = -1;
pd_controller.d_gain = -1;


