%% Sim Sun Sensor Model Init File
%   Husky-Sat1, ADCS Subsystem
%   T. Reynolds: 5.22.17

function sunsensor = init_sun_sensor( )


sunsensor.sample_time_s = (1/100);  % [Hz]
% Variance estimates for each axis
sunsensor.deg_err       = 0.1;
sunsensor.varx          = sunsensor.deg_err/(50*sqrt(3));
sunsensor.vary          = sunsensor.deg_err/(50*sqrt(3));
sunsensor.varz          = sunsensor.deg_err/(50*sqrt(3));

sunsensor.noise         = 1;        % noise on/off
sunsensor.resolution    = 1e-6;     % resolution
sunsensor.valid_pct     = 99;       % over 10 seconds

end