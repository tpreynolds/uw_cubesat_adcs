%% Target Generation unit test init file
% UW HuskySat-1, ADCS Subsystem
%
% Test 1: Coordinate rotation test for TEME to ECI. Runs the simulink file
% coord_rotations_test.slx using example from Vallado 4ed, pp 233-234. Compares
% the outputs against the values given in the book.
%
% Test 2: Coordinate rotation test for ECEF to ECI. Runs the simulink file
% coord_rotations_test.slx using example 3-15 from Vallado 4ed, pp 230-231. 
% Compares the outputs against the values given in the book.
%
% Test 3: Time conversion test.
%
%  Last Update: T. Reynolds 2.3.18
%% Assuming sim_init.m has been run
close all; clc
set(0,'defaulttextinterpreter','latex');

% Constants
JD_2_cent   = 1/(36525);
JD_2_sec    = 86400;
sec_2_JD    = 1/86400;
sec_2_cent  = 1/(86400*36525);
dut1        = 0.204241;
ut1_2_tt    = 32.184 + 32 + dut1;
JD_J2000    = 2451545.0;

% Choose test
run_test    = 2;

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

rERR    = norm(rECI - rECI_comp(1,:)');
vERR    = norm(vECI - vECI_comp(1,:)');
% ----- End Analysis ----- %

disp(['Position error is: ',num2str(1e3*rERR),' m | ', ...
        'Velocity error is: ',num2str(1e3*vERR),' m/s'])


%save('workspace-test-NAME.mat')

elseif run_test == 2
%% Test 2
% Date-time is 2004-04-06-07-51-27.946047 UT1

% Inputs
t_end  = 1;
dut1    = -0.4399619;
s_frac  = 0.946047;                         % Fractional part of UT1 seconds
JD      = 2453101.827396 + sec_2_JD*s_frac; % Converted date-time w/o fractional seconds online.
JD_ut1_cent     = JD_2_cent*(JD - JD_J2000);
JD_tt_cent      = 0.0426236319;             % From the example.
% initial vectors
rECI    = [ -1033.4793830; 7901.2952754; 6380.3565958 ];
vECI    = [ -3.225636520; -2.872451450; 5.531924446 ];
% desired vectors
rECEF   = [ 5102.508958; 6123.01152; 6378.136928 ];
vECEF   = [ -4.74322016; 0.79053650; 5.53375528 ];
% ----- end inputs ----- %

% Simulation parameters
run_time    = num2str(t_end);
mdl         = 'coord_rotations_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% ----- Analyze Results ----- %
rECEF_comp    = logsout.getElement('rECEF_comp').Values.Data;
vECEF_comp    = logsout.getElement('vECEF_comp').Values.Data;

rERR    = norm(rECEF - rECEF_comp(1,:)');
vERR    = norm(vECEF - vECEF_comp(1,:)');
% ----- End Analysis ----- %

disp(['Position error is: ',num2str(1e3*rERR),' m | ', ...
        'Velocity error is: ',num2str(1e3*vERR),' m/s'])

%save('workspace-test-NAME.mat')
end