function [ GPS_time ] = JDUTC_2_GPS( JD_J2000_UTC,fsw_params )
% ----------------------------------------------------------------------- %
% Husky-Sat 1, ADCS Subsystem
% 
% Convert a JD_J2000_TT into the GPS epoch and SoW-Week.
%
%
% T. Reynolds -- 3.9.18
% ----------------------------------------------------------------------- %
% #codegen

% Constants
gps2utc     = fsw_params.constants.time.gps2utc;
day2sec     = fsw_params.constants.time.day2sec; 
sec2day     = fsw_params.constants.time.sec2day;
dayinweek   = fsw_params.constants.time.week2day;
JD_GPSepoch = fsw_params.constants.time.JD_GPSepoch;
JD_J2000    = fsw_params.constants.time.JD_J2000;

% Map input to GPS time frame
JD_J2000_GPS    = JD_J2000_UTC - sec2day*gps2utc;
JD_GPS          = JD_J2000_GPS + JD_J2000;
JD_GPS_since_epoch    = JD_GPS - JD_GPSepoch;

% Convert to SoW and Week
week    = floor(JD_GPS_since_epoch/dayinweek);
sec_of_week    = day2sec * (JD_GPS_since_epoch - week*dayinweek);

% Output
GPS_time = [ sec_of_week; week ];

end

