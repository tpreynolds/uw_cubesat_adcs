function [r_eci_km,v_eci_kmps] = TLE2ECI(orbit_tle)
% HuskySat-1, ADCS Subsystem
% Last Update: T. Reynolds - 12.7.17

mu  = 398600.4418; %  Standard gravitational parameter for the earth [km/s2]
deg2rad     = pi/180;   

INC     = orbit_tle(4) * deg2rad; % Inclination [rad]           
RAAN    = orbit_tle(5) * deg2rad; % Right Ascension of the Ascending Node [rad]
ECC     = orbit_tle(6);           % Eccentricity 
AOP     = orbit_tle(7) * deg2rad; % Argument of periapsis [rad]
MNA     = orbit_tle(8) * deg2rad; % Mean anomaly [rad]
MNM     = orbit_tle(9);           % Mean motion [Revs per day]

% Orbital elements

a = (mu/(MNM*2*pi/(24*3600))^2)^(1/3);     % Semi-major axis [km]    

% solve kepler'1 equation for true anomaly
[~,TRA] = kepler1(MNA,ECC);

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

r_eci_km     = r;
v_eci_kmps   = v;

end

function [eanom, tanom] = kepler1(manom, ecc)

% solve Kepler's equation for circular,
% elliptic and hyperbolic orbits

% Danby's method

% input

%  manom = mean anomaly (radians)
%  ecc   = orbital eccentricity (non-dimensional)

% output

%  eanom = eccentric anomaly (radians)
%  tanom = true anomaly (radians)

% Orbital Mechanics with MATLAB

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% define convergence criterion
ktol = 1.0e-10;
pi2 = 2 * pi;
xma = manom - pi2 * fix(manom/pi2);

% initial guess
if (ecc == 0)    
    % circular orbit
    tanom = xma;    
    eanom = xma;    
    return;
    
elseif (ecc < 1)
    % elliptic orbit  
    eanom = xma + 0.85 * sign(sin(xma)) * ecc;
else   
    % hyperbolic orbit
    eanom = log(2.0 * xma / ecc + 1.8);
end

% perform iterations
niter = 0;

while(1)
    % elliptic orbit    
    s = ecc * sin(eanom);
    c = ecc * cos(eanom);
    
    f = eanom - s - xma;
    fp = 1 - c;
    fpp = s;
    fppp = c;
        
    niter = niter + 1;

    % check for convergence
    if (abs(f) <= ktol || niter > 20)
        break;
    end

    % update eccentric anomaly
    delta = -f / fp;
    deltastar = -f / (fp + 0.5 * delta * fpp);
    deltak = -f / (fp + 0.5 * deltastar * fpp ...
        + deltastar * deltastar * fppp / 6);
    eanom = eanom + deltak;
end
    
% elliptic orbit
sta = sqrt(1 - ecc * ecc) * sin(eanom);
cta = cos(eanom) - ecc;
tanom = atan3(sta, cta);

end