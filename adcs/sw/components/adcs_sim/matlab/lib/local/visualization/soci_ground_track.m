% This script propagates the current SOCi orbit that is stored in
%
%   fsw_params.env_estimation.orb_estimation.sgp4.orbit_tle
%
% in order to plot the ground track and predict UW ground station passes.
% To change the orbit, you must change what TLE is loaded by `sim_init.m`
% 
% For fast prediction, turn off the plotting function by setting PLOT=false
% and DEBUG=false. This will propagate the orbit using the SGP-4 method,
% which is AN APPROXIMATION ONLY. The longer you propagate the orbit for,
% the less you should trust the results. Short term predictions (<4 days)
% should be fine.
%
% The plot that is generate has the camera's field of view outlined in red,
% the ground track plotted in red, and the UW ground station in cyan. After
% 30 minutes of propagation the tail of the ground track will start to
% disappear - this is just so that the plot doesn't get too big and start
% to really slow down.
%
% A ground station pass is defined by the elevation above the horizon, and
% can be set by changing the variable `elev`. For example, SOCi
% communication hardware should be able to communicate with the satellite
% whenever it has an elevation of at least 15 degress above the local
% horizon at the UW ground station.
%
% Printing format is YYYY:MM:DD - HH:MM:SS.S
%
% YOU MUST RUN SIM_INIT.M FIRST BEFORE RUNNING THIS FILE
%
% T. Reynolds -- RAIN Lab

close all; clc;

% simulation options
MET     = 0.0;       % initial MET in [s]
MET_end = 3*86400.0;       % end MET in [s]
theta   = 56;           % camera FoV half angle
elev    = 15;           % elevation above ground station where s/c is visible
DEBUG   = false;        % prints extra information per iterate when true
PLOT    = false;         % generates a plot of ground track when true
lat_T   = 47.655548;    % ground station latitude
lon_T   = -122.303200;  % ground station longitude
alt_T   = 0.0;          % ground station altitude

% constants [DO NOT CHANGE]
sec2day   = fsw_params.constants.time.sec2day;
day2cent  = fsw_params.constants.time.JD2cent;
gps2utc   = fsw_params.constants.time.gps2utc;
utc2gps   = -gps2utc;
gps2tt    = fsw_params.constants.time.gps2tt;
JD_J2000  = fsw_params.constants.time.JD_J2000;
km2m      = fsw_params.constants.convert.KM2M;
m2km      = fsw_params.constants.convert.M2KM;
Re        = 6378.137 * km2m;
H         = norm(fsw_params.constants.ic.pos_ecef_m) - Re;
c         = tand(theta);
passes    = 0;
passing   = false;
kk        = 1;
dT        = 1;    
dR        = 30;
kk_tot    = 200/dT;
psc       = cell(kk_tot,1);
lens      = NaN(100,1);
ECEF_T    = lla2ecef([lat_T,lon_T,alt_T])';
LLDATA    = NaN(2,MET_end/(30*dT));

% initial conditions [DO NOT CHANGE]
orbit_tle       = fsw_params.env_estimation.orb_estimation.sgp4.orbit_tle;
JD_J2000_epoch  = orbit_tle(2);
dut1            = fsw_params.constants.time.dut1; % s

% initialize figure
if (PLOT)
    fig = figure;
    ax  = axes('Parent',fig);
    axis([-180 180 -90 90]);
    Earth_im = imread('Flat_earth.jpg');
    imagesc([-180 180],[-90 90],flipud(Earth_im));
    set(gca,'YDir','normal');
    hold on
    pc = plot(1,1,'Visible','off');  
    plot(lon_T,lat_T,'c*','MarkerSize',3,'MarkerFaceColor','c')
%     hold off
    set(fig,'Units','Normalized','Position',[0.46736,0.42667,0.53264,0.51111]);
    set(gca,'XTick',-180:30:180);
    set(gca,'YTick',-90:15:90);
    set(gca,'XGrid','on','YGrid','on','GridAlpha',0.2);
end

% main loop
while(true)
   
    % current UTC time
    JD_J2000_utc = JD_J2000_epoch + (sec2day * MET);
    
    % map current time to other frames
    JD_J2000_ut1 = JD_J2000_utc + dut1;
    JD_J2000_TT  = JD_J2000_utc + sec2day * ( utc2gps + gps2tt );
    T_J2000_ut1  = day2cent * JD_J2000_ut1;
    T_J2000_TT   = day2cent * JD_J2000_TT;
        
    % coordinate transformations
    [ecef_to_eci,~,~,teme_to_eci] = ...
                            coordinate_rotations(T_J2000_ut1, T_J2000_TT);
    eci_to_ecef = ecef_to_eci';
    
    % propagate position with SGP4
    [pos_teme_km,~,FLAG] = my_sgp4_matlab(JD_J2000_utc,orbit_tle);
    
    % map TEME position to ECEF frame in meters
    pos_ecef_m = km2m * ( eci_to_ecef * teme_to_eci * pos_teme_km );
    
    % map to LLA
    lla = ecef2lla( reshape(pos_ecef_m,1,3) );
    
    % get camera fov
    [ll_circle] = get_ground_circle(lla,Re,c);
    
    % plot point
    if (PLOT)
        if (mod(MET,dR)==0)
            kk_ = mod(kk,kk_tot)+1;
            if (kk>kk_tot)
                delete(psc{kk_});
            end
            figure(fig)
            delete(pc);
            psc{kk_} = plot(lla(2),lla(1),'ro','MarkerSize',3,'MarkerFaceColor','r');
    %         pc = plot(ll_circle(:,2),ll_circle(:,1),'r');
            kk = kk + 1;
        end
    else
        if (mod(MET,dR)==0)
            LLDATA(:,kk) = [ lla(2); lla(1) ];
            kk = kk + 1;
        end
    end
    
    if (DEBUG)
        fprintf('MET=%2.2f s  lat=%2.2f deg  long=%2.2f deg  alt=%2.2f km  FLAG=%d',...
                MET,lla(1),lla(2),lla(3)*m2km,FLAG); %#ok
    end
    
    % find elevation above seattle horizon for assessing passes
    r_ecef_err  = pos_ecef_m - ECEF_T;
    r_sez_err   = rot(90-lat_T,'y') * rot(lon_T,'z') * r_ecef_err;
    r_mag       = norm(r_sez_err);
    s_ell       = r_sez_err(3)/r_mag;
    c_ell       = norm(r_sez_err(1:2))/r_mag;
    ell         = acosd(c_ell);

    if (DEBUG)
        fprintf('  elev=%2.2f deg  rho_z=%2.2f\n',ell,r_sez_err(3));
    end
    
    % check if we are overhead
    if (s_ell>=0)
        
        % starting or ending a pass
        if (abs(ell)>(elev) && ~passing)
            passes  = passes + 1;
            JD      = JD_J2000_epoch + JD_J2000 + sec2day * MET;
            time    = get_timestamp(JD);
            fprintf('--------------------------------------------------\n');
            fprintf('START ground pass: #%02d at %04d:%02d:%02d - %02d:%02d:%04.1f\n',...
                passes,time(1),time(2),time(3),time(4),time(5),time(6));
            passing = true;
            lens(passes) = MET;
        elseif ( (abs(ell)<elev) && passing )
            JD      = JD_J2000_epoch + JD_J2000 + sec2day * MET;
            time    = get_timestamp(JD);
            fprintf('END ground pass:   #%02d at %04d:%02d:%02d - %02d:%02d:%04.1f\n',...
                passes,time(1),time(2),time(3),time(4),time(5),time(6));
            passing = false;
            lens(passes) = MET - lens(passes);
        end
    end
    
    % increment time
    MET = MET + dT;
    
    % exit loop when we reach MET_end
    if (MET>MET_end)
        break;
    end
end
mu_len  = mean(rmmissing(lens));
std_len = std(rmmissing(lens));
fprintf('==================================================\n');
fprintf('TOTAL passes: %d, TIME overhead: %2.2f +/- %2.2fs \n\n',...
            passes,mu_len,std_len);
        
% Plot ground track afterwards if not done during sim
if (~PLOT)
    fig = figure;
    ax  = axes('Parent',fig);
    axis([-180 180 -90 90]);
    Earth_im = imread('Flat_earth.jpg');
    imagesc([-180 180],[-90 90],flipud(Earth_im));
    set(gca,'YDir','normal');
    hold on
    pc = plot(1,1,'Visible','off');  
    plot(lon_T,lat_T,'c*','MarkerSize',3,'MarkerFaceColor','c')
    plot(LLDATA(1,:),LLDATA(2,:),'ro','MarkerSize',3,'MarkerFaceColor','r')
    set(fig,'Units','Normalized','Position',[0.46736,0.42667,0.53264,0.51111]);
    set(gca,'XTick',-180:30:180);
    set(gca,'YTick',-90:15:90);
    set(gca,'XGrid','on','YGrid','on','GridAlpha',0.2);
    
end
%% HELPER FUNCTIONS

function [ll_circle] = get_ground_circle(lla,Re,c)

z0  = lla(3) + Re;
z   = (c^2*z0 + sqrt(c^2*(Re^2-z0^2) + Re^2))/(c^2+1);
a   = sqrt(Re^2-z^2);
xi  = 0:0.1:2*pi;

lambda  = lla(2);       % longitude
phi     = 90 - lla(1);  % co-lattitude
coordT  = [ a.*cos(xi); a.*sin(xi); z.*ones(size(xi)) ];
ECEF    = rot(-lambda,'z') * rot(-phi,'y') * coordT;
LLA     = ecef2lla(ECEF');

ll_circle = LLA(:,1:2);

end

function C = rot(a,type)
switch type
    case 'x'
        C = [ 1 0 0;
              0 cosd(a) sind(a);
              0 -sind(a) cosd(a) ];
    case 'y'
        C = [ cosd(a) 0 -sind(a);
                0   1   0;
                sind(a)  0   cosd(a) ];
    case 'z'
        C = [ cosd(a) sind(a) 0;
              -sind(a) cosd(a) 0;
              0     0    1 ];
    otherwise
        error('ROT: input type must be one of x, y, or z')
end
end

function time = get_timestamp(JD)
% This algorithm is based on Vallado 4e algorithm 22, pp 202.
%
% Input 'JD' is a Julian Date

% Constants
JD_1900     = 2415019.5;
Lmonth      = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

% Convert JD to date-time
T1900   = (JD - JD_1900)/365.25; % base epoch is 1900
year    = 1900 + floor(T1900);

leapyrs = floor((year - 1900 - 1)*0.25);
days    = (JD - JD_1900) - ((year - 1900)*365 + leapyrs );

if days < 1
    year    = year - 1;
    leapyrs = floor((year - 1900 - 1)*0.25);
    days    = (JD - JD_1900) - ((year - 1900)*365 + leapyrs );
end

if mod(year,4) == 0
    Lmonth(2) = 29;
end

dayofyear   = floor(days);

day     = 0;
month   = 0;

while day < dayofyear
    month   = month + 1;
    day = day + Lmonth(month);
end

%dayofmonth = dayofyear - (day - Lmonth(month));

tau     = 24*( days-dayofyear );
hour    = floor( tau );
min     = floor( 60*(tau - hour) );
sec     = 3600*( tau - hour - (min/60) );

time    = [ year, month, dayofyear, hour, min, sec ];
end
