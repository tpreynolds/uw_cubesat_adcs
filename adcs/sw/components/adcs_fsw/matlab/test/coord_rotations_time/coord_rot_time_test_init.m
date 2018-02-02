%% Target Generation unit test init file
% UW HuskySat-1, ADCS Subsystem
%
% Test 1: Coordinate rotation test. Runs the simulink file
% coord_rotations_test.slx using two examples from Vallado 4ed. Compares
% the outputs against the values given in the book.
%
% Test 2: Time conversion test. 
%
%  Last Update: T. Reynolds 2.3.18
%% Assuming sim_init.m has been run
close all; clc
set(0,'defaulttextinterpreter','latex');

% Constants
JD_2_cent   = 1/(36525);
sec_2_cent  = 1/(86400*36525);
dut1        = 0.204241;
ut1_2_tt    = 32.184 + 32 + dut1;

% Choose test
run_test    = 1;

%% Test 1

if run_test == 1

% ----- Inputs ----- %
t_end       = 1;
JD          = 182.78495062;
% initial vectors
rTEME       = [ -9060.47373569; 4658.70952502; 813.68673153 ];
vTEME       = [ -2.232832783; -4.110453490; -3.157345433 ];
% desired vectors
rECI        = [ -9059.9413786; 4659.6972000; 813.9588875 ];
vECI        = [ -2.233348094; -4.110136162; -3.157394074 ];
% ----- end inputs ---- %

% Run Sim
run_time    = num2str(t_end);
mdl         = 'coord_rotations_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
rECI_comp    = logsout.getElement('rECI_comp').Values.Data;
vECI_comp    = logsout.getElement('vECI_comp').Values.Data;



% ----- End Analysis ----- %


%save('workspace-test-NAME.mat')

elseif run_test == 2
%% Test 2

% Load bus stub definitions
load('bus_definitions.mat')

% Load parameters for both flight software and simulation
fsw_params = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Overrides
t_end       = 5400;
sc_mode     = 32;
sc2gs_eci_unit  = zeros(3,1);
% -----

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'target_generation_test2';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
quat        = logsout.getElement('quat').Values.Data;
omega       = logsout.getElement('body_rates').Values.Data;
quat_cmd    = logsout.getElement('quat_cmd').Values.Data;
omega_cmd   = logsout.getElement('omega_cmd_radps').Values.Data;


% ----- End Analysis ----- %

figure(1)
subplot(2,1,1), hold on
plot(tout,quat)
plot(tout,quat_cmd,'--')
title('Quaternion','FontSize',15)
subplot(2,1,2), hold on
plot(tout,omega)
plot(tout,omega_cmd,'--')
title('Angular Velocity [rad/s]','FontSize',15)
xlabel('Time [s]','FontSize',12)

%save('workspace-test-NAME.mat')
end