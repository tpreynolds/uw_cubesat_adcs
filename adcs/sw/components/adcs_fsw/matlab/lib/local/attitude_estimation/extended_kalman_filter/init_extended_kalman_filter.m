function ekf = init_extended_kalman_filter(sim_params)

% ----------------------------------------------------------------------- %
% Loads the parameters of the EKF estimator using predefined fsw_params.
%   Any block added should be initialized and defined in here.

% UW HuskySat-1, ADCS Team
% Last Edited: T. Reynolds 6.24.17
% ----------------------------------------------------------------------- %

% Initial conditions
ekf.ic.quat_est_init = [1 0 0 0]';
ekf.ic.rate_est_init = [0 0 0]';
ekf.ic.bias_est_init = 3*pi/180*[-1 1 1]';
ekf.ic.bias_est_init = [0 0 0]';
ekf.ic.error_cov = blkdiag((3*pi/180)^2*eye(3),(0.3*pi/180)^2*eye(3));

% Sample time
ekf.sample_time_s = 1/10;
dt = ekf.sample_time_s;

% Process and measurement covariances
sig_v = sim_params.sensors.gyro.arw;
sig_u = sim_params.sensors.gyro.rrw;
ekf.proc_cov = [(sig_v^2*dt + 1/3*sig_u^2*dt^3)*eye(3)    -(1/2*sig_u^2*dt^2)*eye(3);
                                   -(1/2*sig_u^2*dt^2)*eye(3)              (sig_u^2*dt)*eye(3)];
ekf.meas_cov = diag([sim_params.sensors.magnetometer.deg_err^2*ones(1,3), sim_params.sensors.sun_sensor.deg_err^2*ones(1,3)]);
   

