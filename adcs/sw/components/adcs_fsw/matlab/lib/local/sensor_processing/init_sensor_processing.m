function sensors = init_sensors_fsw( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all sensor parameters to be used in FSW.
%
%   Last Edited: T. Reynolds 6.23.17
% ----------------------------------------------------------------------- %

% ----- Magnetometer ----- %
sensors.magnetometer.bias = [0 0 0]';
sensors.magnetometer.process_matrix     = eye(3);
% ------------------------ %

% ----- Gyro ----- %

% ---------------- %

% ----- Sun Sensor ----- %

% ---------------------- %

end

