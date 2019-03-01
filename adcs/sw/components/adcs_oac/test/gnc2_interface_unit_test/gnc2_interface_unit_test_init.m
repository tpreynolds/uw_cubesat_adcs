% Unit test file for GNC-2 interface library
%
% T. Reynolds -- RAIN Lab

% problem parameters stored in init_SOACer
N = 10; % number of discretization nodes
w_max = 0.3;
T_max = 1e-3;

rng(2) % for repeatability of random IC

% initial conditions
ax  = [1;1;1]./norm([1;1;1]);
ang = 30*randn;
quat_in  = [ cosd(ang/2); sind(ang/2).*ax ];
omega_in = 0.01.*randn(3,1);

% final conditions
quat_cmd  = [ 1.0; 0.0; 0.0; 0.0 ];
omega_cmd  = [ 0.0; 0.0; 0.0 ];

% inertial sun vector
sI_unit  = [ 1.0; 0.0; 0.0 ];

% epoch and GPS time
GPS_epoch = sim_params.environment.sgp4.gps_time;

% Load sim and set run time
run_time    = 10;
mdl         = 'gnc2_interface_unit_test';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));

% run test case
sim(mdl);

%% analyze results

