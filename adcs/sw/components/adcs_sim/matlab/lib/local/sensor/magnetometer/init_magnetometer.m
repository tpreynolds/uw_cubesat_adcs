function magnetometer = init_magnetometer

magnetometer.sample_time_s = (1/40); % From doc 
magnetometer.err_x = 2.76466e-7; % Based on MAG3110 noise from Jeff
magnetometer.err_y = 2.65772e-7; % Based on MAG3110 noise from Jeff
magnetometer.err_z = 3.20028e-7; % Based on MAG3110 noise from Jeff
magnetometer.noise = 1;
magnetometer.resolution = 100;
magnetometer.valid_pct  = 70;