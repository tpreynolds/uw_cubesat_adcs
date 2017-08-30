function bdot = init_bdot_controller( fsw_params )

% ----------------------------------------------------------------------- %
% Loads the parameters of the b-dot controller using predefined fsw_params.
%   Any block added should be initialized and defined in here.

% UW HuskySat-1, ADCS Subsystem
% Last Edited: T.Reynolds 8.29.17

% ----------------------------------------------------------------------- %

% Initial conditions
bdot.ic.RT_mt_on        = 0;
bdot.ic.RT_b_meas_valid = 0;
bdot.ic.RT_b_body_T     = [0 0 0]';
bdot.ic.RT_dig_val      = [0 0 0]';
bdot.ic.derivative      = 0;
bdot.ic.unit_delay      = [0 0 0]';
bdot.ic.invalid_input   = [0 0 0]';

% Library parameters

% Make sure gains are negative
bdot.gain_matrix = diag([- fsw_params.actuators.magnetorquer.max_dipole_x/2e-6,...
                         - fsw_params.actuators.magnetorquer.max_dipole_y/2e-6,...
                         - fsw_params.actuators.magnetorquer.max_dipole_z/3e-6]);

% NOTE: 3e-6 is the cut off value of \dot{B} below which we no longer want to be
% saturating the torque rods.

% -----
bdot.sample_time_s  = 1/10; %[s] - sampling at 10Hz
bdot.digital_value  = 255; 
bdot.cutoff_freq    = 2*pi*0.1; % [rad/s]
bdot.continuous_lpf = tf([bdot.cutoff_freq],[1 bdot.cutoff_freq]);
bdot.discrete_lpf   = c2d(bdot.continuous_lpf,bdot.sample_time_s);
[bdot.filter_num,bdot.filter_den]   = tfdata(bdot.discrete_lpf,'v');
% Extract second component only for use in filter
bdot.filter_num     = bdot.filter_num(2);
bdot.filter_den     = bdot.filter_den(2);

bdot.dv_2_m_X   = fsw_params.actuators.magnetorquer.max_dipole_x/bdot.digital_value;
bdot.m_2_dv_X   = 1/bdot.dv_2_m_X;

bdot.dv_2_m_Y   = fsw_params.actuators.magnetorquer.max_dipole_y/bdot.digital_value;
bdot.m_2_dv_Y   = 1/bdot.dv_2_m_Y;

bdot.dv_2_m_Z   = fsw_params.actuators.magnetorquer.max_dipole_z/bdot.digital_value;
bdot.m_2_dv_Z   = 1/bdot.dv_2_m_Z;

