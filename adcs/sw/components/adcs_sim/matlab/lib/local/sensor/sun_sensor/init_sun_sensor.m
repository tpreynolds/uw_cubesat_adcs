%% Sim Sun Sensor Model Init File
%   Husky-Sat1, ADCS Subsystem
%   T. Reynolds: 5.22.17

%% 
function sunsensor = init_sunsensor_sim( )


sunsensor.sample_time_s = (1/100);  % [Hz]
sunsensor.deg_err       = 0.1;      % placeholder
sunsensor.noise         = 1;        % noise on/off
sunsensor.resolution    = 1e-6;     % resolution
sunsensor.valid_pct     = 99;       % over 10 seconds

end