function magnetometer = init_magnetometer
% ----------------------------------------------------------------------- %
%INIT_MAGNETOMETER  
%
%   Sim Magnetometer Model Init File. Uses HS-1 noise data.
% 
% T. Reynolds -- 8.3.17
% ----------------------------------------------------------------------- %

magnetometer.sample_time_s  = (1/40); % From doc 
magnetometer.err_x          = 1.637696e-7; % Based on MAG3110 noise from Thu
magnetometer.err_y          = 9.22938e-8;  % Based on MAG3110 noise from Thu
magnetometer.err_z          = 1.343961e-7; % Based on MAG3110 noise from Thu
magnetometer.deg_err        = 1.2074e-6; % Computed from noise above
magnetometer.noise          = 1; % Toggle noise on/off
magnetometer.resolution     = 1e-8;
magnetometer.valid_pct      = 95;

end