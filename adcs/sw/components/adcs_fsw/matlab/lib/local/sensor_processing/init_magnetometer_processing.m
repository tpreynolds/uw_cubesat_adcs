function [ magnetometer ] = init_magnetometer_processing( )
% ----------------------------------------------------------------------- %
%INIT_MAGNETOMETER_PROCESSING     Magnetometer Processing Init File
%
% Initializes all parameters used for processing magnetometer readings.
%
% T. Reynolds -- 7.18.18
% ----------------------------------------------------------------------- %

% Library sample time
magnetometer.sample_time_s    = (1/20); % Hz

% Soft and hard iron biases
magnetometer.bias             = [0 0 0]';
magnetometer.process_matrix   = eye(3);

% DCM to map from sensor frame to body frame
magnetometer.sensor2body      = eye(3);

% Output for invalid sensor reading
magnetometer.invalid_input    = zeros(3,1);

% Filter coefficients
magnetometer.cutoff_freq    = 2*pi*0.1; % rad/s
magnetometer.continuous_lpf = ...
              tf([magnetometer.cutoff_freq],[1 magnetometer.cutoff_freq]);
magnetometer.discrete_lpf   = ...
              c2d(magnetometer.continuous_lpf,magnetometer.sample_time_s);
[magnetometer.filter_num,magnetometer.filter_den] = ...
              tfdata(magnetometer.discrete_lpf,'v');
          
% Extract second component only for use in filter
magnetometer.filter_num     = magnetometer.filter_num(2);
magnetometer.filter_den     = magnetometer.filter_den(2);

end

