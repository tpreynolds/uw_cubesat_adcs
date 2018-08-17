function [orbit_tle, jd_epoch_days] = get_tle(filename)

fid = fopen(filename);

tline1  = fgetl(fid);
tline2  = fgetl(fid);
TLE     = tline2;

% Parse TLE
y           = str2double(tline1(19:20));        % epoch year
day_dec     = str2double(tline1(21:32));        % epoch (decimal day)
MNMdot      = str2double(['0.' tline1(35:43)]);  % first derivative of MNM
MNMddot     = str2double(tline1(46:50));        % second derivative of MNM
B_star      = str2double(['0.' tline1(55:59)]); % BSTAR drag term
B_star_ex   = str2double(tline1(60:61));        % BSTAR drag term (exponential)
INC         = str2double(TLE(9:16));            % Inclination [deg]
RAAN        = str2double(TLE(18:25));           % Right Ascension of Ascending Node [deg]
ECC         = str2double(['0.' TLE(27:33)]);    % Eccentricity [-]
AOP         = str2double(TLE(35:42));           % Argument of Perigee [deg]
MNA         = str2double(TLE(44:51));           % Mean Anomaly at Epoch [deg]
MNM         = str2double(TLE(53:63));           % Mean Motion [revs/day]

epoch_year          = 2000 + y;
% compute JD for Jan 1, epoch_year, 00:00:00 UTC
jd_begin_of_year    = 367*epoch_year - floor((7/4)*(epoch_year + floor(10/12))) + floor(275/9) + 1721013.5;
jd_epoch_days       = day_dec + jd_begin_of_year;
jd_epoch_days_J2000 = jd_epoch_days - 2451545.0;

B_star      = B_star*10^(B_star_ex); 

orbit_tle   = [y; jd_epoch_days_J2000; B_star; INC; RAAN; ECC; AOP; MNA; MNM];

end