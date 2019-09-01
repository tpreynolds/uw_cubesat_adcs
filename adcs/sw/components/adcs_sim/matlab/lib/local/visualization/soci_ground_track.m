close all; clc;
DEBUG = false;

% constants
sec2day   = fsw_params.constants.time.sec2day;
day2cent  = fsw_params.constants.time.JD2cent;
gps2utc   = fsw_params.constants.time.gps2utc;
utc2gps   = - gps2utc;
gps2tt    = fsw_params.constants.time.gps2tt;
km2m      = fsw_params.constants.convert.KM2M;
m2km      = fsw_params.constants.convert.M2KM;

% initial conditions
orbit_tle       = fsw_params.env_estimation.orb_estimation.sgp4.orbit_tle;
JD_J2000_epoch  = orbit_tle(2);
dut1            = fsw_params.constants.time.dut1; % s
MET             = 0.0;

% simulation parameters
MET_end = 1000.0;
dT      = 1;
c       = tand(30);
Re      = 6378.137 * km2m;

% initialize figure
fig = figure;
ax  = axes('Parent',fig);
axis([-180 180 -90 90]);
Earth_im = imread('Flat_earth.jpg');
imagesc([-180 180],[-90 90],Earth_im);
hold on
pc = plot(1,1,'Visible','off');
hold off
set(fig,'Units','Normalized','Position',[0.46736,0.42667,0.53264,0.51111]);
set(gca,'XTick',-180:30:180);
set(gca,'YTick',-90:15:90);
set(gca,'XGrid','on','YGrid','on','GridAlpha',0.2);

while(true)
   
    % current UTC time
    JD_J2000_utc = JD_J2000_epoch + (sec2day * MET);
    
    JD_J2000_ut1 = JD_J2000_utc + dut1;
    JD_J2000_TT  = JD_J2000_utc + sec2day * ( utc2gps + gps2tt );
    T_J2000_ut1  = day2cent * JD_J2000_ut1;
    T_J2000_TT   = day2cent * JD_J2000_TT;
        
    % coordinate transforms
    [ecef_to_eci,~,~,teme_to_eci] = ...
                            coordinate_rotations(T_J2000_ut1, T_J2000_TT);
    eci_to_ecef = ecef_to_eci';
    
    % propagate position
    [pos_teme_km,~,FLAG] = my_sgp4_matlab(JD_J2000_utc,orbit_tle);
    
    % map to ECEF in meters
    pos_ecef_m = km2m * ( eci_to_ecef * teme_to_eci * pos_teme_km );
    
    % map to LLA
    lla = ecef2lla( reshape(pos_ecef_m,1,3) );
    
    % get camera fov
    [ll_circle] = get_ground_circle(lla,Re,c);
    
    % plot point
    figure(fig), hold on
    delete(pc);
    plot(lla(2),lla(1),'ro','MarkerSize',3,'MarkerFaceColor','r')
    pc = plot(ll_circle(:,2),ll_circle(:,1),'r');
    hold off
    
    if (DEBUG)
        fprintf('MET=%2.2f s  lat=%2.2f deg  long=%2.2f deg  alt=%2.2f km  FLAG=%d\n',...
                MET,lla(1),lla(2),lla(3)*m2km,FLAG); %#ok
    end
    
    % increase time
    MET = MET + dT;
    
    if (MET>MET_end)
        break;
    end
end

%% HELPER FUNCTIONS

function [ll_circle] = get_ground_circle(lla,Re,c)

z0  = lla(3) + Re;
z   = (c^2*z0 + sqrt(c^2*(Re^2-z0^2) + Re^2))/(c^2+1);
a   = sqrt(Re^2-z^2);
xi  = 0:0.1:2*pi;

lambda = lla(2);        % longitude
phi     = 90 - lla(1);  % co-lattitude
C_1    = [  cosd(-lambda)   sind(-lambda)   0;
           -sind(-lambda)   cosd(-lambda)   0;
            0               0               1 ];
C_2    = [  cosd(-phi)      0              -sind(-phi);
            0               1               0;
            sind(-phi)      0               cosd(-phi) ];
C_FT    = C_1 * C_2;
coordT = [ a.*cos(xi); a.*sin(xi); z.*ones(size(xi)) ];
ECEF    = C_FT * coordT;
LLA     = ecef2lla(ECEF');

ll_circle = LLA(:,1:2);

end
