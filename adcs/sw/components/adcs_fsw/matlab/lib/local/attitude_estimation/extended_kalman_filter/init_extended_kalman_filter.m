function ekf = init_extended_kalman_filter(sim_params)

% ----------------------------------------------------------------------- %
% Loads the parameters of the EKF estimator using predefined fsw_params.
%   Any block added should be initialized and defined in here.

% UW HuskySat-1, ADCS Team
% Last Edited: T. Reynolds 8.8.17
% ----------------------------------------------------------------------- %

% Library sample time
ekf.sample_time_s = 1/10;

% Initial conditions
ekf.ic.quat_est_init = [1 0 0 0]';
ekf.ic.rate_est_init = [0 0 0]';
ekf.ic.bias_est_init = [0 0 0]';
% Initial covariance from Crassidis Ex. 7.1 pp. 460.
P_0_a = 3.0462e-6;  % attitude
P_0_b = 9.4018e-13; % bias
ekf.ic.error_cov = blkdiag(P_0_a*eye(3),P_0_b*eye(3));
    % rate transition blocks
    ekf.ic.rt_valid_gyro    = 0;
    ekf.ic.rt_valid_mag     = 0;
    ekf.ic.rt_valid_sun     = 0;
    ekf.ic.rt_mt_power_ok   = 0;
    ekf.ic.rt_sc_in_sun     = 0;
    ekf.ic.rt_w_body_radps  = zeros(3,1);
    ekf.ic.rt_mag_body      = zeros(3,1);
    ekf.ic.rt_mag_eci_est   = zeros(3,1);
    ekf.ic.rt_sun_body      = zeros(3,1);
    ekf.ic.rt_sun_eci_est   = zeros(3,1);
    ekf.ic.rt_meas_cov      = zeros(6);

% Upper bound on convergence time
ekf.converge_time_s   = 60;

% Constant matrices
ekf.G   = blkdiag(-eye(3),eye(3));
% This dt MUST be the rate at which information in the KF is updated!
ekf.dt  = ekf.sample_time_s;

% Process and measurement covariances
sig_v   = sim_params.sensors.gyro.arw;
sig_u   = sim_params.sensors.gyro.rrw;
dt      = ekf.dt;
mag_err = sim_params.sensors.magnetometer.nrm_err;
sun_err = sim_params.sensors.sun_sensor.deg_err;

ekf.proc_cov = [(sig_v^2*dt + 1/3*sig_u^2*dt^3)*eye(3)    -(1/2*sig_u^2*dt^2)*eye(3);
                   -(1/2*sig_u^2*dt^2)*eye(3)              (sig_u^2*dt)*eye(3)];
ekf.meas_cov = diag([mag_err*ones(1,3), sun_err*ones(1,3)]);

end
   

