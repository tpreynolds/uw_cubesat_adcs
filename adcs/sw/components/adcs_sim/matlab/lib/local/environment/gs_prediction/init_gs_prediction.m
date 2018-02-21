function gs_prediction = init_gs_prediction( fsw_params )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initialize all parameters for the sun vector estimation
%
%   Last Edited: S. Rice 1/6/2018
% ----------------------------------------------------------------------- %

% ----- Earth parameters ----- %
gs_prediction.fov_ang  = 30; % [degrees]
% ---------------------------- %

% Sample time
gs_prediction.sample_time_s     = fsw_params.sample_time_s;

% UW Ground Station 
gs_prediction.latlon = [47.6553;-122.3035];
gs_prediction.alt   = 0.0;




end