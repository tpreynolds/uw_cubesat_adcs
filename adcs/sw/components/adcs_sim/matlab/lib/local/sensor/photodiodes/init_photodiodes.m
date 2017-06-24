%% Photodiode Sim Model Init File
%   UW Husky-Sat1, ADCS Subsystem
%   T. Reynolds 5.27.17

function photodiodes = init_photodiodes

photodiodes.sample_time_s = (1/10); % From doc 
photodiodes.err_x = 5e-1; 
photodiodes.err_y = 5e-1; 
photodiodes.err_z = 5e-1; 
photodiodes.noise = 1;
photodiodes.resolution = 1e-5;

