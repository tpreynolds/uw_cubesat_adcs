%% SC in Eclipse Unit Test
%   UW HuskySat-1, ADCS Subsystem
%   Author: T. Reynolds 
%   Last update: 9.1.17
% ----------------------------------------------------------------------- %
% Test 1: Uses SWISSCUBE ephemeris. Uses SGP4 to propagate the orbit and
% determine if a line of sight vector to the ground station exists.
%
%
% Test 2: Uses QUAKESAT ephemeris. USes SGP4 to propagate the orbit.
% QUAKESAT is a polar sun-sync orbit, so should always have a line of sight
% to the sun. 
%
%   - Plots show trajectory and mid point sun vector, and whether or
%      not the sc has a LoS to the sun.
%   - Plots show ground track
%   - Ref. Vallado p. 301 and 279

% Get right paths
% addpath(genpath(pwd))
% cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_bdot/matlab/
% addpath(genpath(pwd))
% cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/
% addpath(genpath(pwd))
% cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_sim/matlab/

addpath(genpath(pwd))
addpath(genpath('../../adcs_fsw/matlab/'))
addpath(genpath('../../adcs_bdot/matlab/'))

%% Test 1
clear variables; close all; clc
figdir      = './figs/';
datadir     = './data/';

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);
fsw_params.bdot     = init_bdot_controller(fsw_params);

% ----- Overrides ----- %
REKM = 6378.135; % earth radius [km]
sgp4.tle_filename = 'SWISSCUBE.tle'; % the right TLE
[sgp4.orbit_tle,sgp4.JD_epoch_days] = get_tle(sgp4.tle_filename);
fsw_params.bus.orbit_tle = sgp4.orbit_tle;
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
% ----- End Overrides ---- %

% Run sim
run_time = '6400';
mdl = 'gs_vector_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% Analysis

% Extract data
sc2gs_unit = logsout.getElement('sc2gs_unit').Values.Data;
sc2gs_unit_time = logsout.getElement('sc2gs_unit').Values.Time;

sc_above_gs = logsout.getElement('sc_above_gs').Values.Data;
sc_above_gs_time = logsout.getElement('sc_above_gs').Values.Time;

sc_pos_eci = logsout.getElement('pos_eci_km').Values.Data;
sc_pos_eci_time = logsout.getElement('pos_eci_km').Values.Time;
JD_ut1 = logsout.getElement('jd_j2000_ut1').Values.Data;

mid = floor(length(sc_pos_eci_time)/2);

% avg_sc2gs  = (2*REKM).*sc2gs_unit(mid,:); 

figure(1), hold on
[X, Y, Z]=sphere(100);
X=X.*REKM;
Y=Y.*REKM;
Z=Z.*REKM;
Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
surf(X, Y, Z,'CData',flip(Earth_im,1),'FaceColor','texturemap','EdgeColor','none');
% plot3(sc_pos_eci(:,1),sc_pos_eci(:,2),sc_pos_eci(:,3),'r','LineWidth',2)
plot3(sc_ecef.Data(:,1),sc_ecef.Data(:,2),sc_ecef.Data(:,3),'r','LineWidth',2)
plot3(gs_ecef.Data(1,1),gs_ecef.Data(1,2),gs_ecef.Data(1,3),'mx','LineWidth',8)
% quiver3(0,0,0,avg_sc2gs(1),avg_sc2gs(2),avg_sc2gs(3),'LineWidth',2)
xlabel('x-direction [km]')
ylabel('y-direction [km]')
zlabel('z-direction [km]')
%saveas(gcf, strcat(figdir, 'traj_visualization_test1'),'fig')

% figure(2), hold on
% Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
% imshow(Earth_im);

figure(3)
plot(sc_above_gs_time,sc_above_gs)
xlabel('Time [s]')
ylabel('Spacecraft in gs')
%saveas(gcf, strcat(figdir, 'sc_above_gs_test1'),'fig')

%save(strcat(datadir, 'workspace_test_1'))

%% Test 2
clear variables; close all; clc
figdir      = './figs/';
datadir     = './data/';

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);
fsw_params.bdot     = init_bdot_controller(fsw_params);

% ----- Overrides ----- %
REKM    = 6378.135; % earth radius [km]
sgp4.tle_filename = 'QUAKESAT.tle'; % the right TLE
[sgp4.orbit_tle,sgp4.JD_epoch_days] = get_tle(sgp4.tle_filename);
fsw_params.bus.orbit_tle = sgp4.orbit_tle;
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
% ----- End Overrides ---- %

% Run sim
run_time = '6400';
mdl = 'gs_vector_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% Analysis

% Extract data
sc2gs_unit = logsout.getElement('sc2gs_unit').Values.Data;
sc2gs_unit_time = logsout.getElement('sc2gs_unit').Values.Time;

sc_above_gs = logsout.getElement('sc_above_gs').Values.Data;
sc_above_gs_time = logsout.getElement('sc_above_gs').Values.Time;

sc_pos_eci = logsout.getElement('pos_eci_km').Values.Data;
sc_pos_eci_time = logsout.getElement('pos_eci_km').Values.Time;
JD_ut1 = logsout.getElement('jd_j2000_ut1').Values.Data;

mid = floor(length(sc_pos_eci_time)/2);

% avg_sc2gs  = (2*REKM).*sc2gs_unit(mid,:); 

figure(1), hold on
[X, Y, Z]=sphere(100);
X=X.*REKM;
Y=Y.*REKM;
Z=Z.*REKM;
Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
surf(X, Y, Z,'CData',flip(Earth_im,1),'FaceColor','texturemap','EdgeColor','none');
% plot3(sc_pos_eci(:,1),sc_pos_eci(:,2),sc_pos_eci(:,3),'r','LineWidth',2)
plot3(sc_ecef.Data(:,1),sc_ecef.Data(:,2),sc_ecef.Data(:,3),'r','LineWidth',2)
plot3(gs_ecef.Data(1,1),gs_ecef.Data(1,2),gs_ecef.Data(1,3),'mx','LineWidth',8)
% quiver3(0,0,0,avg_sc2gs(1),avg_sc2gs(2),avg_sc2gs(3),'LineWidth',2)
xlabel('x-direction [km]')
ylabel('y-direction [km]')
zlabel('z-direction [km]')
%saveas(gcf, strcat(figdir, 'traj_visualization_test1'),'fig')

% figure(2), hold on
% Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
% imshow(Earth_im);

figure(3)
plot(sc_above_gs_time,sc_above_gs)
xlabel('Time [s]')
ylabel('Spacecraft in gs')
%saveas(gcf, strcat(figdir, 'sc_above_gs_test1'),'fig')

%save(strcat(datadir, 'workspace_test_1'))
