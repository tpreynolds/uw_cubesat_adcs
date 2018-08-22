function sunsensor = init_sun_sensor( fsw_params )
% ----------------------------------------------------------------------- %
%INIT_SUN_SENSOR    
%
% Sim Sun Sensor Model Init File
%
% T. Reynolds -- 5.22.17
% ----------------------------------------------------------------------- %

DEG2RAD = fsw_params.constants.convert.deg2rad;

sunsensor.sample_time_s = 1/20;  % [Hz]

% Variance estimates for each axis
sunsensor.deg_err       = 0.1;
sunsensor.varx          = DEG2RAD * sunsensor.deg_err/(50*sqrt(3));
sunsensor.vary          = DEG2RAD * sunsensor.deg_err/(50*sqrt(3));
sunsensor.varz          = DEG2RAD * sunsensor.deg_err/(50*sqrt(3));

sunsensor.range_deg     = 60;

sunsensor.noise         = 1;        % noise on/off
sunsensor.resolution    = 1e-6;     % resolution

end