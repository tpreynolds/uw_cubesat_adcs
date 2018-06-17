function gyro = init_gyroscope( )
% ----------------------------------------------------------------------- %
%INIT_GYROSCOPE Gyroscope Model Init File
%
% UW HuskySat-1, ADCS Team
% 
% T. Reynolds -- 8.3.17
% ----------------------------------------------------------------------- %

gyro.sample_time_s  = (1/100);      % [Hz]
gyro.arw            = 1e-3;         % angle random walk
gyro.rrw            = 1e-3;         % rate random walk
gyro.resolution     = 1e-5;         % resolution of sensor
gyro.valid_pct      = 99;           % over 10 seconds
gyro.bias_init      = 0.0*(pi/180)*[1 1 1]';     % Initial bias

end