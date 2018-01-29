function sensor_processing = init_sensor_processing( fsw_params )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all sensor parameters to be used in FSW.
%
%   Last Edited: T. Reynolds 1.24.18
% ----------------------------------------------------------------------- %

% ----- Magnetometer ----- %
sensor_processing.magnetometer.bias             = [0 0 0]';
sensor_processing.magnetometer.process_matrix   = eye(3);
sensor_processing.magnetometer.sensor2body      = eye(3);
sensor_processing.magnetometer.rate             = (1/20); % Hz - sensor read rate
% ------------------------ %

% ----- Gyro ----- %
sensor_processing.gyro.sensor2body  = eye(3);
sensor_processing.gyro.rate         = (1/50); % Hz - sensor read rate
sensor_processing.gyro.cutoff_freq  = 2*pi*1; % [rad/s]
sensor_processing.gyro.c_lpf        = tf([sensor_processing.gyro.cutoff_freq],...
                                        [1 sensor_processing.gyro.cutoff_freq]);
sensor_processing.gyro.d_lpf        = c2d(sensor_processing.gyro.c_lpf,sensor_processing.gyro.rate);
[sensor_processing.gyro.filter_num,sensor_processing.gyro.filter_den] = ...
                                        tfdata(sensor_processing.gyro.d_lpf,'v');
sensor_processing.gyro.filter_num   = sensor_processing.gyro.filter_num(2);
sensor_processing.gyro.filter_den   = sensor_processing.gyro.filter_den(2);
% ---------------- %

% ----- Sun Sensor ----- %
sensor_processing.sunsensor.bias            = [0 0 0]';
sensor_processing.sunsensor.process_matrix  = eye(3);
sensor_processing.sunsensor.sensor2body     = eye(3);
sensor_processing.sunsensor.rate            = (1/10); % Hz - sensor read rate
% ---------------------- %

% ----- GPS Sensor ----- %
sensor_processing.gps.ic.time = [fsw_params.environment.sgp4.gps_sec_init ...
                                 fsw_params.environment.sgp4.gps_week_init]';
[sensor_processing.gps.ic.pos,sensor_processing.gps.ic.vel]    = TLE2ECI(fsw_params.environment.sgp4.orbit_tle);
sensor_processing.gps.ic.all    = [sensor_processing.gps.ic.pos; ...
                                    sensor_processing.gps.ic.vel; ...
                                    sensor_processing.gps.ic.time;
                                    1 ];
sensor_processing.gps.sample_time_s     = 1;
sensor_processing.gps.rate  = 1; % Hz - sensor read rate
% ---------------------- %


% ----- Photodiodes ----- %
sensor_processing.photodiodes.rate  = (1/2); % Hz - sensor read rate
% ---------------------- %

end

