function sensor_processing = init_sensor_processing( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all sensor parameters to be used in FSW.
%
%   Last Edited: T. Reynolds 8.15.17
% ----------------------------------------------------------------------- %

% ----- Magnetometer ----- %
sensor_processing.magnetometer.bias = [0 0 0]';
sensor_processing.magnetometer.process_matrix     = eye(3);
% ------------------------ %

% ----- Gyro ----- %
sensor_processing.gyro.bias     = [0 0 0]';
sensor_processing.gyro.process_matrix   = eye(3);
% ---------------- %

% ----- Sun Sensor ----- %
sensor_processing.sunsensor.bias     = [0 0 0]';
sensor_processing.sunsensor.process_matrix   = eye(3);
% ---------------------- %

% ----- GPS Sensor ----- %
sensor_processing.gps.ic.time = [0 0]';
sensor_processing.gps.sample_time_s     = 1;
% ---------------------- %

end

