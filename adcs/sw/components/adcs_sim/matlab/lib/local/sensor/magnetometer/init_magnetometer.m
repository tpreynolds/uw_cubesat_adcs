%% Sim Gyroscope Model Init File
%   Husky-Sat1, ADCS Subsystem
%   T. Reynolds: 8.3.17

function magnetometer = init_magnetometer

magnetometer.sample_time_s = (1/40); % From doc 
magnetometer.err_x = 2.76466e-7; % Based on MAG3110 noise from Jeff
magnetometer.err_y = 2.65772e-7; % Based on MAG3110 noise from Jeff
magnetometer.err_z = 3.20028e-7; % Based on MAG3110 noise from Jeff
magnetometer.deg_err    = 1.2074e-6; % Computed from noise above
magnetometer.noise = 1; % Toggle noise on/off
magnetometer.resolution = 100;
magnetometer.valid_pct  = 70;