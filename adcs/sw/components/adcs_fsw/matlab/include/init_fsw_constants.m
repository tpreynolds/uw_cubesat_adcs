function [ constants ] = init_fsw_constants()
% ----------------------------------------------------------------------- %
%INIT_FSW_CONSTANTS
%
% Define constants used anywhere in FSW.
%
% T.Reynolds -- 2.28.17
% ----------------------------------------------------------------------- %

% Time
constants.time.dut1         = 0.06420;
constants.time.dAT          = 37.0;
constants.time.gps2tai      = 19.0;
constants.time.gps2tt       = 32.184 + constants.time.gps2tai;
constants.time.gps2utc      = constants.time.gps2tai - constants.time.dAT;
constants.time.gps2ut1      = constants.time.gps2utc + constants.time.dut1;
constants.time.sec2day      = 1/86400;
constants.time.day2sec      = 86400;
constants.time.week2day     = 7;
constants.time.JD_GPSepoch  = 2444244.5;
constants.time.JD_J2000     = 2451545.0;
constants.time.JD2cent      = 1/36525;
constants.time.cent2JD      = 36525;

% Conversions
constants.convert.KM2M          = 1e3;
constants.convert.M2KM          = 1e-3;
constants.convert.NT2T          = 1e-9;
constants.convert.RPM_2_radps   = (pi/30);
constants.convert.radps_2_RPM   = (30/pi);
constants.convert.revpday_2_radpmin     = 2*pi/1440;
constants.convert.deg2rad       = pi/180;
constants.convert.rad2deg       = 180/pi;
constants.convert.asec2rad      = 1/3600 * constants.convert.deg2rad;
constants.convert.rev2rad       = 2*pi;
constants.convert.rad2rev       = 1/(2*pi);

% Mag field approx
x   = load('mag_field_approx.mat');
constants.mag.b0    = x.x(1:3);
constants.mag.b1    = x.x(4:6);
constants.mag.b2    = x.x(7:9);
constants.mag.b3    = x.x(10:12);
constants.mag.b4    = x.x(13:15);
constants.mag.b5    = x.x(16:18);
constants.mag.b6    = x.x(19:21);

% Misc.
constants.twopi     = 2*pi;
constants.o_prec    = 7.292115146706979e-5;


end

