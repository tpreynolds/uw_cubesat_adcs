%% Magnetic vector unit test init file

% Test 1: Run a static test at an arbitrary lat/long/atl to test against
% any online B-field computer. I've compared to:
% http://geomag.nrcan.gc.ca/calc/mfcal-en.php.

% Test 2: 

% UW HuskySat-1, ADCS Subsystem
%  Last Update: T. Reynolds 12.5.17
%% Load paths and stuff needed
clear variables;

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);
fsw_params.bdot     = init_bdot_controller(fsw_params);



%% Test 1

% Overrides
% Seattle lat/lon with estimated altitude
lat     = 47.663888888888889;
lon     = -122.301111111111111;
alt     = 500; %km
% -----

t_end = 10;

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'mag_vec_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
%   extract pos/vel/time data from sim
mag_vec_eci_T = logsout.getElement('mag_vec_eci_T').Values.Data;
mag_vec     = mag_vec_eci_T(end,:);

% Compare this value to whatever online computer gives for the same
% lat/lon/alt.
nrm_nT     = 1e9*norm(mag_vec);
nrm_nT_des  = 53482; % field strength for lat/lon/alt according to reference

% ----- Plot Results ----- %
diff    = abs(nrm_nT - nrm_nT_des);
disp(['Test 1: Difference in computed field strength is: ', num2str(diff),'nT']);

%save('workspace-disturbances-test1.mat')

