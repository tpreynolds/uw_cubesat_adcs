function orbit_els = tle2orb(orbit_tle)
%TLE2ORB
%
% orb_els = tle2orb(orbit_tle) provides a set of classical orbital elements
% in the following format:
%   orb_els(1) = semi major axis [km]
%   orb_els(2) = eccentricity [-]
%   orb_els(3) = inclination [deg]
%   orb_els(4) = right ascension of ascending node [deg]
%   orb_els(5) = argument of perigee [deg]
%   orb_els(6) = eccentric anomaly [deg]
%
% T. Reynolds -- RAIN Lab
mu  = 398600.4418; %  Standard gravitational parameter for the earth
   
INC     = orbit_tle(4);      % Inclination [deg]           
RAAN    = orbit_tle(5);      % Right Ascension of the Ascending Node [deg]
ECC     = orbit_tle(6);      % Eccentricity 
AOP     = orbit_tle(7);      % Argument of periapsis [deg]
MNA     = orbit_tle(8);      % Mean anomaly [deg]
MNM     = orbit_tle(9);     % Mean motion [Revs per day]

% Orbital elements

a = (mu/(MNM*2*pi/(24*3600))^2)^(1/3);     % Semi-major axis [km]    

% Calculate the eccentric anomaly using Mean anomaly
err = 1e-10;            %Calculation Error
E0 = MNA; t =1;
itt = 0;

while(t) 
       E =  MNA + ECC*sind(E0);
      if ( abs(E - E0) < err)
          t = 0;
      end
      E0 = E;
      itt = itt+1;
end

% Six orbital elements 
orbit_els = [a ECC INC RAAN AOP E];