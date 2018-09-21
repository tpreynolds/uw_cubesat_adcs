function sgp4   = init_sgp4(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_SGP4   
% 
% UW HusySat-1, ADCS Team
%
%   Init file for sgp4 library.
%
%   T. Reynolds -- 2.10.18
%   updated: T. Reynolds -- 9.20.18 -- added TLE_gen functionality
% ----------------------------------------------------------------------- %

    % Conversions
    DEG2RAD         = fsw_params.constants.convert.deg2rad;
    REVpD2RADpM     = fsw_params.constants.convert.revpday_2_radpmin;
    
    % Define our orbit
    YMDHMS  = [ 2019; 1; 1; 0; 0; 0 ];
    INC     = 54.6146;  % inclination
    RAAN    = 247.4627; % right ascension of ascending node
    ECC     = 0006703; % keep this w/o decimals and 7 digits
    AOP     = 130.5360; % arg of perigee
    MNA     = 325.0288; % mean anomaly
    MNM     = 15.72125391; % mean motion
    
    % Generate TLE (saved as text file in /adcs_sim/matlab/include/TLEs/
    sgp4.orbit_tle = TLE_gen(YMDHMS, INC, RAAN, ECC, AOP, MNA, MNM);

    % Add individual quantities to SGP4 struct (correct units)
    sgp4.year    = sgp4.orbit_tle(1);
    sgp4.JD_UTC_epoch_J2000 = sgp4.orbit_tle(2);
    sgp4.B_star  = sgp4.orbit_tle(3);
    sgp4.INC     = sgp4.orbit_tle(4)*DEG2RAD;       % [rad]
    sgp4.RAAN    = sgp4.orbit_tle(5)*DEG2RAD;       % [rad]
    sgp4.ECC     = sgp4.orbit_tle(6);               % [-]
    sgp4.AOP     = sgp4.orbit_tle(7)*DEG2RAD;       % [rad]
    sgp4.MNA     = sgp4.orbit_tle(8)*DEG2RAD;       % [rad]
    sgp4.MNM     = sgp4.orbit_tle(9)*REVpD2RADpM;   % [rad/min]

    % Compute initial GPS time
    sgp4.gps_time       = JDUTC_2_GPS(sgp4.JD_UTC_epoch_J2000,fsw_params);
    sgp4.gps_week_init  = sgp4.gps_time(2);
    sgp4.gps_sec_init   = sgp4.gps_time(1);

end