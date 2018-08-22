function sunsensor = init_sun_sensor( )
% ----------------------------------------------------------------------- %
%INIT_SUN_SENSOR    
%
% Sim Sun Sensor Model Init File
%
% T. Reynolds -- 5.22.17
% ----------------------------------------------------------------------- %

% Sensor sample time
sunsensor.sample_time_s = 1/20;  % [Hz]

% Variance estimates for each axis
sunsensor.deg_err       = 0.05;
sunsensor.varx          = sunsensor.deg_err/(50*sqrt(3));
sunsensor.vary          = sunsensor.deg_err/(50*sqrt(3));
sunsensor.varz          = sunsensor.deg_err/(50*sqrt(3));

% Field of view half-angle
sunsensor.range_deg     = 60;

sunsensor.noise         = 1;        % noise on/off
sunsensor.resolution    = 1e-9;     % resolution

end