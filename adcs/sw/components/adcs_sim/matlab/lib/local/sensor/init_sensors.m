function sensors = init_sensors( fsw_params )
% ----------------------------------------------------------------------- %
%INIT_SENSORS
%
% Initializes all sensor parameters for the SIM
%
% T. Reynolds -- 8.3.17
% ----------------------------------------------------------------------- %

sensors.gps             = init_gps();
sensors.gyro            = init_gyroscope();
sensors.magnetometer    = init_magnetometer();
sensors.photodiodes     = init_photodiodes();
sensors.sun_sensor      = init_sun_sensor(fsw_params);

end