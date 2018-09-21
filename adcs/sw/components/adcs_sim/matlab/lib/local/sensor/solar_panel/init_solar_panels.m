function solar_panel = init_solar_panels(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_SOLAR_PANELS   
%
% Sim solar panel model init file
%
% T. Reynolds -- 5.22.17
% ----------------------------------------------------------------------- %

% Sample time
solar_panel.sample_time_s = fsw_params.sample_time_s;  % [Hz]

solar_panel.faces    = [ 1 -1  0  0  0  0;
                         0  0  1 -1  0  0;
                         0  0  0  0  1 -1 ];
solar_panel.maxPower = [ 7.5; 7.5; 6.5; 6.5; 0.0; 0.0 ];
solar_panel.num      = sum(solar_panel.maxPower>0);


end