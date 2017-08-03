function sensor_processing = init_sensor_processing( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all sensor parameters to be used in FSW.
%
%   Last Edited: T. Reynolds 8.3.17
% ----------------------------------------------------------------------- %

% ----- Magnetometer ----- %
sensor_processing.magnetometer.bias = [0 0 0]';
sensor_processing.magnetometer.process_matrix     = eye(3);
% ------------------------ %

% ----- Gyro ----- %

% ---------------- %

% ----- Sun Sensor ----- %

% ---------------------- %

end

