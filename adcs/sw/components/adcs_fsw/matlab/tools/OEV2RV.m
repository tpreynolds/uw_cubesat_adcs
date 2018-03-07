function [r_km,v_kmps] = OEV2RV(orbit_tle)
% ----------------------------------------------------------------------- %
% HuskySat-1, ADCS Subsystem
% Last Update: T. Reynolds - 12.7.17
%
% Computes an inertial position and velocity from a set of orbital
% elements.
% ----------------------------------------------------------------------- %

% Constants
mu          = 398600.4418; % [km3/s2]
deg2rad     = pi/180;   
twopi       = 2 * pi;
day2sec     = 86400;

INC     = orbit_tle(4) * deg2rad; % Inclination [rad]           
RAAN    = orbit_tle(5) * deg2rad; % Right Ascension of the Ascending Node [rad]
ECC     = orbit_tle(6);           % Eccentricity [-]
AOP     = orbit_tle(7) * deg2rad; % Argument of periapsis [rad]
MNA     = orbit_tle(8) * deg2rad; % Mean anomaly [rad]
MNM     = orbit_tle(9) * (twopi / day2sec); % Mean motion [rad/s]

% Orbital elements
a = (mu/(MNM^2))^(1/3);     % Semi-major axis [km]    

% solve kepler's equation for true anomaly
[~,TRA] = kepler(MNA,ECC);

% Six orbital elements 
% orb_els = [a ECC INC RAAN AOP E];

% ----- Compute r_eci, v_eci ----- %
r = zeros(3, 1);
v = zeros(3, 1);

slr = a * (1 - ECC * ECC);

rm = slr / (1 + ECC * cos(TRA));
   
arglat = AOP + TRA;

sarglat = sin(arglat);
carglat = cos(arglat);
   
c4 = sqrt(mu / slr);
c5 = ECC * cos(AOP) + carglat;
c6 = ECC * sin(AOP) + sarglat;

sinc = sin(INC);
cinc = cos(INC);

sraan = sin(RAAN);
craan = cos(RAAN);

% position vector

r(1) = rm * (craan * carglat - sraan * cinc * sarglat);
r(2) = rm * (sraan * carglat + cinc * sarglat * craan);
r(3) = rm * sinc * sarglat;

% velocity vector

v(1) = -c4 * (craan * c6 + sraan * cinc * c5);
v(2) = -c4 * (sraan * c6 - craan * cinc * c5);
v(3) = c4 * c5 * sinc;

r_km     = r;
v_kmps   = v;

end

function [E, TRA] = kepler(MNA, ECC)
% solve Kepler's equation for elliptic orbits using Newton-Raphson

% Constants
tol     = 1e-8;
twopi   = 2 * pi;
i_max   = 10;

% Project onto [-2pi,2pi]
if( abs(MNA) > twopi )
    MNA = sign(MNA)*twopi;
end

% Initial guess
if( (-pi < MNA && MNA < 0) || (MNA > pi) )
    E   = MNA - ECC;
else
    E   = MNA + ECC;
end

% Run Loop
Enew    = 1e6;
for i = 1:i_max
    err     = abs(E - Enew);
    if( err < tol )
        E   = Enew;
        break;
    end
    den     = 1 - ECC*cos(E);
    if( abs(den) > tol ) % avoid dividing by zero
        Enew    = E + (MNA - E + ECC*sin(E))/den;
    else
        Enew    = E;
    end
end

% Compute true anomaly
sta = sqrt(1 - ECC * ECC) * sin(E);
cta = cos(E) - ECC;
TRA = atan3(sta, cta);

end

