function photodiodes = init_photodiodes
% ----------------------------------------------------------------------- %
%INIT_PHOTODIODES
%
%   Photodiode sensor init file.
%
% T. Reynolds -- 8.8.17
% ----------------------------------------------------------------------- %

photodiodes.sample_time_s   = (1/10); % From doc 
photodiodes.err_x           = 5e-1; % WAG
photodiodes.err_y           = 5e-1; 
photodiodes.err_z           = 5e-1; 
photodiodes.noise           = 1;
photodiodes.resolution      = 1e-5;

end

