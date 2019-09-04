%% SGP4 Orbit Propagator
% UW Husky-Sat1 - ADCS Subsystem team
%   Author:     Taylor Reynolds
%   Updated:    7/3/18
% Based on "SpaceTrack Report #3: Models for Propagation of NORAD Element
% Sets", Hoots & Roerhrich, 1980.
%
% TLE Format:
%   Line 1: Column | Description
%           01          line number of element data
%           03-07       satellite number
%           08          classification (u = unclassified)
%           10-11       last two digits of launch year
%           12-14       launch number of year
%           15-17       piece of launch
%           19-20       epoch year (last two digits)
%           21-32       epoch (DOY and fractional portion of the day)
%           34-43       first derivative of the mean motion
%           45-52       second time derivative of mean motion (decimal
%                           assumed)
%           54-61       BS drag term (decimal point assumed)
%           63          ephemeris type
%           65-68       element number
%           69          checksum (mod 10)
%   
%   Line 2: Column  | Description
%           01          line number of element data
%           03-07       satellite number
%           09-16       inclination (degrees)
%           18-25       right ascension of the ascending node (degrees)
%           27-33       eccentricity (decimal assumed)
%           35-42       argument of perigee (degrees)
%           44-51       mean anomaly (degrees)
%           53-63       mean motion (revs per day)
%           64-68       revolution number at epoch (revs)
%           69          checksum (mod 10)
%
% ----------------------------------------------------------------------- %
% Inputs:
%   - orbit_tle: NORAD two line element set containing orbit info
%   - tsince: Time since epoch of TLE in MINUTES
% Outputs:
%   - pos_frame: Position vector in the TEME frame  
%   - vel_frame: Velocity vector in the TEME frame
%
% Variables:
%   - n_o = SGP type "mean" mean motion at epoch
%   - e_o = the "mean" eccentricity at epoch
%   - i_o = the "mean" inclination at epoch
%   - M_o = the "mean" mean anomaly at epoch
%   - w_o = the "mean" argument of perigee at epoch
%   - Om_o = the "mean" longitude of ascending node at epoch
%   - nd_o  = the TRoC of n_o
%   - ndd_o = the TRoC of nd_o
%   - Bs = the SGP4 type drag coefficient
%   - k_e = gravitational constant of Earth, sqrt(GM_e)
%   - a_E = the equatorial radius of Earth in ER
%   - J_2 = the second gravitation zonal harmonic of Earth
%   - J_3 = the third gravitational zonal harmonic of Earth
%   - J_4 = the fourth gravitational zonal harmonic of Earth
%   - (t-t_0) = time since epoch
%   - k_2   = 0.5*J_2*a_E^2
%   - k_4   = -(3/8)*J_4*a_E^4
%   - A_30  = -J_3*a_E^3
%   - q_0   = parameter for the SGP4 density function
%   - s     = parameter for the SGP4 density function

% ----------------------------------------------------------------------- %
%% Function Body
function [pos_teme_km,vel_teme_kmps,FLAG] = my_sgp4_matlab(JD_J2000_cur,orbit_tle)
%#codegen
% ----------------------------------------------------------------------- %
% LOAD CONSTANTS
% ----------------------------------------------------------------------- %
    k_2     = 5.413080e-4;      % CK2 = 0.5*J_2*a_E^2
    k_4     = 0.62098875e-6;    % CK4 = -3/8*J_4*a_E^4
    QOMS4   = 1.88027916e-9;    % QOMS2T = (q_0 - s)^4 * ER^4
    s       = 1.01222928;       % S = s*ER
    XJ3     = -0.2538815e-5;    % J_3
    XKE     = 0.743669161e-1;   % XKE = k_e*(ER/min)^{3/2}
    XKMPER  = 6378.137;         % km/ER
    XMNPDA  = 1440;             % time_units/day
    a_E     = 1;                % distance units/ER
    DE2RA   = 0.174532925e-1;   % radians/degree
    TRUE    = 1;
    FALSE   = 0;
    r_E     = 6378.137;         % Earth's equatorial radius [km]
    A_30    = -XJ3*a_E^3;       % see nomenclature
    VKMPS   = XKMPER/60;        % Convert ER/min velocities to km/s
    J2000   = 2451545.0;        % Julian date for J2000
    FLAG    = 0;
    pos_invalid     = [ XKMPER; XKMPER; XKMPER + 500 ];
    vel_invalid     = [ 0.0; 0.0; 0.0 ];
% ----------------------------------------------------------------------- %
% ----------------------------------------------------------------------- %

% Line 1
epoch_year  = orbit_tle(1);
epoch_JD    = orbit_tle(2);
BS          = orbit_tle(3);

% Line 2
i_o     = orbit_tle(4)*DE2RA;   % Radians (INC)
Om_o    = orbit_tle(5)*DE2RA;   % Radians (RAAN)
e_o     = orbit_tle(6);         % Non-dimensional (ECC)
w_o     = orbit_tle(7)*DE2RA;   % Radians (AOP)
M_o     = orbit_tle(8)*DE2RA;   % Radians (MNA)
n_o     = orbit_tle(9)*2*pi/XMNPDA;  % Revs per time unit (MNM)   

% Hooks on orbital elements (catch #1)
% eccentricity
if( (e_o >= 1) || (e_o <= 0) )
    pos_teme_km       = pos_invalid;
    vel_teme_kmps     = vel_invalid;
    FLAG = -1; 
    return;
end
% mean motion (catch #1)
if( n_o == 0 )
    pos_teme_km       = pos_invalid;
    vel_teme_kmps     = vel_invalid;
    FLAG = -1; 
    return;
end

% Time since epoch (catch #1)                             
tsince_JD      = (JD_J2000_cur - epoch_JD);
if( abs(tsince_JD) < 1e-8 || tsince_JD < 0)
    tsince_JD   = 0;
end

tsince  = XMNPDA*tsince_JD;

a_1  = (XKE/n_o)^(2/3);
d_1  = 1.5*(k_2/(a_1^2))*((3*cos(i_o)^2 - 1)/(1 - e_o^2)^(3/2));
a_o  = a_1*(1 - (1/3)*d_1 - d_1^2 - (134/81)*d_1^3);
d_o  = (3/2)*(k_2/(a_o^2))*((3*cos(i_o)^2 - 1)/(1 - e_o^2)^(3/2));
n_o_pp   = n_o/(1 + d_o);
a_o_pp   = a_o/(1 - d_o);

r_p     = r_E*(a_o_pp*(1 - e_o) - a_E); % Radius of perigee

% Check low altitude condition                                    
if( a_o_pp*(1-e_o)/a_E < (220/XKMPER + a_E) )
    lowAlt  = TRUE;
    FLAG    = 1;
else
    lowAlt  = FALSE;
end

% Check if perigee is between [98,156]km or below 98km and adjust the
% constant s accordingly.
if( (r_p >= 98) && (r_p <= 156) )
    s_star  = a_o_pp*(1 - e_o) - s + a_E;
    QOMS4   = (QOMS4^(0.25) + s - s_star)^4;
    s       = s_star;
elseif( r_p < 98 )
    s_star  = 20/XKMPER + a_E;
    QOMS4   = (QOMS4^(0.25) + s - s_star)^4;
    s       = s_star;
end

% Constants
tht     = cos(i_o);
xi      = 1/(a_o_pp - s); % cannot be zero since s_star = s ~= a_o_pp
b_o     = (1 - e_o^2)^(0.5);
eta     = a_o_pp*e_o*xi; % cannot be zero, but could be 1.
if( eta == 1 ) % check that (1-eta^2) cannot be zero (catch #2)
    pos_teme_km     = pos_invalid;
    vel_teme_kmps   = vel_invalid;
    FLAG = -1;
    return;
end
C_2     = QOMS4*xi^4*n_o_pp*(1-eta^2)^(-7/2)*((a_o_pp*(1 + ...
            (3/2)*eta^2 + 4*e_o*eta + e_o*eta^3)) + ...
            (3/2)*k_2*xi*(-0.5+1.5*tht^2)*(8+24*eta^2+3*eta^4)/(1-eta^2));
C_1     = BS*C_2;
C_3     = (QOMS4*xi^5*A_30*n_o_pp*a_E*sin(i_o))/(k_2*e_o);
C_4     = 2*n_o_pp*QOMS4*xi^4*a_o_pp*b_o^2*(1-eta^2)^(-7/2)* ...
            ((2*eta*(1+e_o*eta) + 0.5*e_o + 0.5*eta^3) - ...
            (2*k_2*xi)/(a_o_pp*(1-eta^2)) * (3*(1-3*tht^2)* ...
            (1-(3/2)*eta^2-2*e_o*eta-0.5*e_o*eta^3) + (3/4)*(1-tht^2)* ...
            (2*eta^2-e_o*eta-e_o*eta^3)*cos(2*w_o)));
C_5     = 0;
D_2     = 0;
D_3     = 0;
D_4     = 0;
IL2     = 1.5*C_1;
IL3     = 0;
IL4     = 0;
IL5     = 0;

if( lowAlt  == FALSE )
    C_5     = 2*QOMS4*xi^4*a_o_pp*b_o^2*(1-eta^2)^(-7/2)*...
                                    (1+(11/4)*eta*(eta+e_o) + e_o*eta^3);
    D_2     = 4*a_o_pp*xi*C_1^2;
    D_3     = (4/3)*a_o_pp*xi^2*(17*a_o_pp + s)*C_1^3;
    D_4     = (2/3)*a_o_pp*xi^3*(221*a_o_pp + 31*s)*C_1^4;
    IL3     = D_2 + 2*C_1^2;
    IL4     = 0.25*(3*D_3 + 12*C_1*D_2 + 10*C_1^3);
    IL5     = 0.2*(3*D_4 + 12*C_1*D_3 + 6*D_2^2 + 30*C_1^2*D_2 + 15*C_1^4);
end

% Secular effects of atm drag and gravitation. Note that a_o_pp ~= 0 and
% b_o ~= 0 so no denoms here are zero.
M_DF    = M_o + ( 1 + (3*k_2*(3*tht^2-1))/(2*a_o_pp^2*b_o^3) + ...
            (3*k_2^2*(13-78*tht^2+137*tht^4))/(16*a_o_pp^4*b_o^7) )* ...
            n_o_pp*tsince;
w_DF    = w_o + ( (-3*k_2*(1-5*tht^2))/(2*a_o_pp^2*b_o^3) + ...
            (3*k_2^2*(7-114*tht^2+395*tht^4))/(16*a_o_pp^4*b_o^8) + ...
            (5*k_4*(3-36*tht^2+49*tht^4))/(4*a_o_pp^4*b_o^8) )*n_o_pp*tsince;        
Om_DF   = Om_o + ( (-3*k_2*tht)/(a_o_pp^2*b_o^4) +...
            (3*k_2^2*(4*tht-19*tht^3))/(2*a_o_pp^4*b_o^8) +...
            (5*k_4*tht*(3-7*tht^2))/(2*a_o_pp^4*b_o^8) )*n_o_pp*tsince;

Om      = Om_DF - (21/2)*( (n_o_pp*k_2*tht)/(a_o_pp^2*b_o^2) )*C_1*tsince^2;

if( lowAlt == FALSE ) % #5 %    
    d_w     = BS*C_3*cos(w_o)*tsince;
    d_M     = -(2/3)*QOMS4*BS*xi^4*(a_E/(e_o*eta))* ...
                ( (1+eta*cos(M_DF))^3 - (1 + eta*cos(M_o))^3 );
    M_p     = M_DF + d_w + d_M;
    w       = w_DF - d_w - d_M;
    e       = e_o - BS*C_4*tsince - BS*C_5*( sin(M_p) - sin(M_o) );
    a       = a_o_pp*( 1 - C_1*tsince - D_2*tsince^2 - D_3*tsince^3 - ...
                D_4*tsince^4 )^2;
    L       = M_p + w + Om + n_o_pp*( IL2*tsince^2 + IL3*tsince^3 +...
            IL4*tsince^4 + IL5*tsince^5 );
else
    M_p     = M_DF;
    w       = w_DF;
    a       = a_o_pp*(1 - C_1*tsince)^2;
    e       = e_o - BS*C_4*tsince;
    L       = M_p + w + Om + n_o_pp*IL2*tsince^2;
end

if( (a == 0) || (e >= 1) ) % catch divide by zero conditions (catch #3)
    pos_teme_km       = pos_invalid;
    vel_teme_kmps     = vel_invalid;
    FLAG = -1;
    return;
end
b       = sqrt(1-e^2);
n       = XKE/(a^(3/2));
                 
% Add the long-period periodic terms
a_xN    = e*cos(w);
L_L     = (A_30*sin(i_o)/(8*k_2*a*b^2))*e*cos(w)*((3+5*tht)/(1+tht));
a_yNL   = A_30*sin(i_o)/(4*k_2*a*b^2);
L_T     = L + L_L;
a_yN    = e*sin(w) + a_yNL;

U       = mod(L_T - Om,2*pi);
Epw     = kepler(U,a_yN,a_xN);
                 
% Preliminary quantities for short-period periodics
ecE     = a_xN*cos(Epw) + a_yN*sin(Epw);
esE     = a_xN*sin(Epw) - a_yN*cos(Epw);
e_L     = (a_xN^2 + a_yN^2)^(1/2);
p_L     = a*(1 - e_L^2);
r       = a*(1 - ecE);
if( (r == 0) || (p_L == 0) ) % (catch #4)
    pos_teme_km       = pos_invalid;
    vel_teme_kmps     = vel_invalid;
    FLAG = -1;
    return;
end
r_dot   = XKE*sqrt(a)*esE/r;
r_f_dot = XKE*sqrt(p_L)/r;
cosu    = (a/r)*( cos(Epw) - a_xN + ((a_yN*esE)/(1+sqrt(1 - e_L^2))) );
sinu    = (a/r)*( sin(Epw) - a_yN - ((a_xN*esE)/(1 + sqrt(1 - e_L^2))) );
u       = atan2(sinu,cosu);
dr      = (k_2/(2*p_L))*(1 - tht^2)*cos(2*u);
du      = -(k_2/(4*p_L^2))*(7*tht^2 - 1)*sin(2*u);
dOm     = (3*k_2*tht/(2*p_L^2))*sin(2*u);
di      = (3*k_2*tht/(2*p_L^2))*sin(i_o)*cos(2*u);
dr_dot  = -((k_2*n)/p_L)*(1-tht^2)*sin(2*u);
dr_f_dot    = (k_2*n/p_L)*( (1-tht^2)*cos(2*u) - (3/2)*(1-3*tht^2) );

% Add the short-period periodics to get osculating elements
r_k     = r*(1 - (3/2)*k_2*sqrt(1 - e_L^2)*(3*tht^2 - 1)/p_L^2) + dr;
u_k     = u + du;
Om_k    = Om + dOm;
i_k     = i_o + di;
r_dot_k     = r_dot + dr_dot;
r_f_dot_k   = r_f_dot + dr_f_dot;

% Create unit orientation vectors
M       = [ -sin(Om_k)*cos(i_k); cos(Om_k)*cos(i_k); sin(i_k)]; 
N       = [ cos(Om_k); sin(Om_k); 0 ];

U       = M.*sin(u_k) + N.*cos(u_k);
V       = M.*cos(u_k) - N.*sin(u_k);

% Find position and velocity in km & km/s
pos_teme_km     = r_k.*U.*XKMPER;
vel_teme_kmps   = (r_dot_k.*U + r_f_dot_k.*V).*(VKMPS);

end


function Epw = kepler(U,a_yN,a_xN)
% Solves Kepler's equation for Epw = E + w using iterative method
tol         = 1e-8;
iter_max    = 10;
Epw         = U;
Epw_new     = 0;
iter        = 0;

while( (abs(Epw - Epw_new) > tol) && (iter < iter_max) )
    Epw     = Epw_new;
    dEpw    = (U-a_yN*cos(Epw) + a_xN*sin(Epw) - Epw)/ ...
                    (-a_yN*sin(Epw) - a_xN*cos(Epw) + 1);
    Epw_new = Epw + dEpw;
    iter    = iter +1;
end

Epw = Epw_new;

end