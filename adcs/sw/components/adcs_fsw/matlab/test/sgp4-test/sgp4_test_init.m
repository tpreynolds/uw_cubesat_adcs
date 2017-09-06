%% SGP4 unit test init file
% Test 1:
%   Compare my SGP4 propagation to data obtained from SWISSCUBE via STK
% Test 2:
%   Compare my SGP4 propagation to data obtained from QUAKESAT via STK

% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 8.30.17
%% Load paths

clear variables; close all; clc;
set(0,'defaulttextinterpreter','latex');

% Start fresh
clear variables; close all; clc
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_sim/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/
addpath(genpath(pwd))
cd ~; cd uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/sgp4-test/


%% Test 1

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
sgp4.tle_filename = 'SWISSCUBE.tle'; % the right TLE
[sgp4.orbit_tle,sgp4.JD_epoch_days] = get_tle(sgp4.tle_filename);
fsw_params.bus.orbit_tle = sgp4.orbit_tle;
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
t_end   = 5400;
% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'sgp4_unit_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
pos_eci_km1 = logsout.getElement('pos_eci_km').Values.Data;
pos_time1 = logsout.getElement('pos_eci_km').Values.Time;

vel_eci_kmps1 = logsout.getElement('vel_eci_kmps').Values.Data;
vel_time1 = logsout.getElement('vel_eci_kmps').Values.Time;

JD_J2000_days1 = logsout.getElement('JD_ut1_J2000_days').Values.Data;
JD_time1 = logsout.getElement('JD_ut1_J2000_days').Values.Time;

% Extract pos/vel data from reference SGP4
% pos_eci_kmK = logsout.getElement('pos_eci_km_K').Values.Data;
% pos_timeK = logsout.getElement('pos_eci_km_K').Values.Time;
% 
% vel_eci_kmpsK = logsout.getElement('vel_eci_kmps_K').Values.Data;
% vel_timeK = logsout.getElement('vel_eci_kmps_K').Values.Time;

%   import STK data
load('SWISSCUBE_data.mat')
x_km    = SWISSCUBE_data{1};
y_km    = SWISSCUBE_data{2};
z_km    = SWISSCUBE_data{3};
pos_true_km     = horzcat(x_km,y_km,z_km);
vx_kmps    = SWISSCUBE_data{4};
vy_kmps    = SWISSCUBE_data{5};
vz_kmps    = SWISSCUBE_data{6};
vel_true_kmps   = horzcat(vx_kmps,vy_kmps,vz_kmps);

%   compare the beginning and end
pos_diff_init1   = norm(pos_eci_km1(1,:) - pos_true_km(1,:));
vel_diff_init1   = norm(vel_eci_kmps1(1,:) - vel_true_kmps(1,:));

pos_diff_end1    = norm(pos_eci_km1(t_end,:) - pos_true_km(t_end,:));
vel_diff_end1    = norm(vel_eci_kmps1(t_end,:) - vel_true_kmps(t_end,:));

pos_drift_per_dt1   = (pos_diff_end1 - pos_diff_init1)/t_end;
vel_drift_per_dt1   = (vel_diff_end1 - vel_diff_init1)/t_end;

% Compare reference beginning and end
% pos_diff_initK   = norm(pos_eci_kmK(1,:) - pos_true_km(1,:));
% vel_diff_initK   = norm(vel_eci_kmpsK(1,:) - vel_true_kmps(1,:));
% 
% pos_diff_endK    = norm(pos_eci_kmK(t_end,:) - pos_true_km(t_end,:));
% vel_diff_endK    = norm(vel_eci_kmpsK(t_end,:) - vel_true_kmps(t_end,:));

% ----- End Analysis ----- %

%save('workspace-test-SWISSCUBE.mat')

% Restart from scratch
clear variables; close all; clc
%% Test 2

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
sgp4.tle_filename = 'QUAKESAT.tle'; % the right TLE
[sgp4.orbit_tle,sgp4.JD_epoch_days] = get_tle(sgp4.tle_filename);
fsw_params.bus.orbit_tle = sgp4.orbit_tle;
% convert Oct 1, 2018 19:00:00 to GPS time
sim_params.sensors.gps.start_sec    = 154800;
sim_params.sensors.gps.start_week   = 2021;
t_end2  = 86400;
% -----

% Simulation parameters
run_time    = num2str(t_end2);
mdl         = 'sgp4_unit_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
pos_eci_km2 = logsout.getElement('pos_eci_km').Values.Data;
pos_time2 = logsout.getElement('pos_eci_km').Values.Time;

vel_eci_kmps2 = logsout.getElement('vel_eci_kmps').Values.Data;
vel_time2 = logsout.getElement('vel_eci_kmps').Values.Time;

JD_J2000_days2 = logsout.getElement('JD_ut1_J2000_days').Values.Data;
JD_time2 = logsout.getElement('JD_ut1_J2000_days').Values.Time;

%   import STK data
load('QUAKESAT_data.mat')
x_km2    = QUAKESAT_data{1};
y_km2    = QUAKESAT_data{2};
z_km2    = QUAKESAT_data{3};
pos_true_km2     = horzcat(x_km2,y_km2,z_km2);
vx_kmps2    = QUAKESAT_data{4};
vy_kmps2    = QUAKESAT_data{5};
vz_kmps2    = QUAKESAT_data{6};
vel_true_kmps2   = horzcat(vx_kmps2,vy_kmps2,vz_kmps2);

%   compare the beginning and end
pos_diff_init2   = norm(pos_eci_km2(1,:) - pos_true_km2(1,:));
vel_diff_init2   = norm(vel_eci_kmps2(1,:) - vel_true_kmps2(1,:));

pos_diff_end2    = norm(pos_eci_km2(t_end2,:) - pos_true_km2(t_end2,:));
vel_diff_end2    = norm(vel_eci_kmps2(t_end2,:) - vel_true_kmps2(t_end2,:));

pos_drift_per_dt2   = (pos_diff_end2 - pos_diff_init2)/t_end2;
vel_drift_per_dt2   = (vel_diff_end2 - vel_diff_init2)/t_end2;

% ----- End Analysis ----- %

%save('workspace-test-QUAKESAT.mat')

