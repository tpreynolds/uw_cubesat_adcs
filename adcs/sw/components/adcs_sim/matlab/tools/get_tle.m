function [orbit_tle, jd_epoch_days] = get_tle(filename)
%GET_TLE
% 
% This function reads a TLE from the file "filename" and outputs an
% orbit_tle vector that contains the relevant information for a sim.
%
% Syntax:   [orbit_tle, jd_epoch_days] = get_tle(filename)
%
% Inputs:
%   - filename [char] : a character array of a TLE file in the current
%                       matlab path
%
% Outputs:
%   - orbit_tle [double] : a 9x1 vector that contains (in order)
%                          orbit_tle(1) = (TLE epoch year) - 2000
%                          orbit_tle(2) = TLE epoch in Julian days ref. to J2000
%                          orbit_tle(3) = the B_star drag term
%                          orbit_tle(4) = inclination [deg]
%                          orbit_tle(5) = right ascension of ascending node [deg]
%                          orbit_tle(6) = argument of perigee [deg]
%                          orbit_tle(7) = mean anomaly [deg]
%                          orbit_tle(8) = mean motion [revolutions/day]
%   - jd_epoch_days [double] : a scalar that gives the epoch of the TLE in
%                              Julian days.
%
% T. Reynolds -- RAIN Lab

fid = fopen(filename);

tline1  = fgetl(fid);
tline2  = fgetl(fid);

% Parse TLE
y           = str2double(tline1(19:20));        % epoch year
day_dec     = str2double(tline1(21:32));        % epoch (decimal day)
MNMdot      = str2double(['0.' tline1(35:43)]);  % first derivative of MNM
MNMddot     = str2double(tline1(46:50));        % second derivative of MNM
B_star      = str2double(['0.' tline1(55:59)]); % BSTAR drag term
B_star_ex   = str2double(tline1(60:61));        % BSTAR drag term (exponential)
INC         = str2double(tline2(9:16));            % Inclination [deg]
RAAN        = str2double(tline2(18:25));           % Right Ascension of Ascending Node [deg]
ECC         = str2double(['0.' tline2(27:33)]);    % Eccentricity [-]
AOP         = str2double(tline2(35:42));           % Argument of Perigee [deg]
MNA         = str2double(tline2(44:51));           % Mean Anomaly at Epoch [deg]
MNM         = str2double(tline2(53:63));           % Mean Motion [revs/day]

epoch_year          = 2000 + y;
% compute JD for Jan 1, epoch_year, 00:00:00 UTC
jd_begin_of_year    = 367*epoch_year - floor((7/4) * (epoch_year + ...
                                    floor(10/12))) + floor(275/9) + 1721013.5;
% compute the epoch of the TLE
jd_epoch_days       = day_dec + jd_begin_of_year;
% subtract the JD of the J2000 epoch to get the TLE epoch referenced to J2000
jd_epoch_days_J2000 = jd_epoch_days - 2451545.0;
% compute the B_star drag term
B_star      = B_star*10^(B_star_ex); 
% Construct the orbit_tle
orbit_tle   = [y; jd_epoch_days_J2000; B_star; INC; RAAN; ECC; AOP; MNA; MNM];

end