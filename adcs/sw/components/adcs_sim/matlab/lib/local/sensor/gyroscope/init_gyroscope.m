function gyro = init_gyroscope( )
% ----------------------------------------------------------------------- %
%INIT_GYROSCOPE Gyroscope Model Init File
%
% UW HuskySat-1, ADCS Team
% 
% T. Reynolds -- 8.3.17
% ----------------------------------------------------------------------- %

gyro.sample_time_s  = (1/100);      % [Hz]
% ARW/RRW/initial bias taken from Crassidis Ex. 7.1 pp 460.
gyro.arw            = sqrt(10)*1e-7;            % angle random walk
gyro.rrw            = sqrt(10)*1e-10;           % rate random walk
gyro.resolution     = 1e-8;                     % resolution of sensor
gyro.bias_init      = 0.1*(1/3600)*(pi/180)*[1 1 1]';   % Initial bias

end