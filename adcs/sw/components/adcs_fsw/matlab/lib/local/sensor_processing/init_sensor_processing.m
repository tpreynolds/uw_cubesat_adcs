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
sensor_processing.magnetometer.rate     = (1/20); % Hz - sensor read rate
% ------------------------ %

% ----- Gyro ----- %
sensor_processing.gyro.bias     = [0 0 0]';
sensor_processing.gyro.process_matrix   = eye(3);
sensor_processing.gyro.rate     = (1/50); % Hz - sensor read rate
% ---------------- %

% ----- Sun Sensor ----- %
sensor_processing.sunsensor.bias     = [0 0 0]';
sensor_processing.sunsensor.process_matrix   = eye(3);
sensor_processing.sunsensor.rate    = (1/10); % Hz - sensor read rate
% ---------------------- %

% ----- GPS Sensor ----- %
sensor_processing.gps.ic.time = [0 0]';
sensor_processing.gps.ic.pos    = zeros(3,1);
sensor_processing.gps.ic.vel    = zeros(3,1);
sensor_processing.gps.sample_time_s     = 1;
sensor_processing.gps.rate  = 1; % Hz - sensor read rate
% ---------------------- %


% ----- Photodiodes ----- %
sensor_processing.photodiodes.rate  = (1/2); % Hz - sensor read rate
% ---------------------- %

end

