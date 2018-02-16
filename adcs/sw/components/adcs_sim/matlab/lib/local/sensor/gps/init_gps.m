function gps = init_gps()
% Initialize the GPS sensor library block.
% HuskySat-1, ADCS Subsystem
% Last Update: T. Reynolds 12.18.17

gps.sample_time_s = 1;
gps.num_sats    = 5;
gps.max_sec     = 604800;
gps.period      = 1800; % [s] roughly one orbit
gps.pct_on      = 1; % turn it on for up to 1% of one orbit
gps.delay_s     = 0; % takes 15s to get a lock

end