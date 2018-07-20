% Bdot Controller Unit test file
%
% This test case uses our dynamics engine and environment models to conduct
% a higher fidelity test of the bdot controller. Should only be run after
% the static test case has been used to vet controller parameters.
%
% Assumes sim_init.m has been run to set the paths

% Start fresh
clear variables; close all; clc
set(0,'defaulttextinterpreter','latex');

% Load bus stub definitions
load('bus_definitions.mat')
load('bus_definitions_fsw.mat')

figdir = './test/figs/';
datadir = './test/data/';

% Test 1:
%   Base line control gain and cut-off frequency values currently slated
%   for flight software
% Test 2:
%   Test control gain and cut-off frequency to try attempt improvements

% RAIN-SAT -- T. Reynolds - 8.19.17

% Toggle to save figures and data. 0 => no save, 1 => save.
save_all = 0;

%% Test 1

% Load parameters for both flight software and simulation
fsw_params              = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);


% ----- Overrides ----- %
sim_params.dynamics.ic.rate_init = [ 0.2; 0.2; 0.2 ];
% sim_params.environment.avg_b = [1.59212e-5 -6.1454e-6 4.0276e-5]; % T
% fsw_params.bdot.gain_matrix    = diag([-0.15/1.5e-6, -0.15/1.5e-6, -0.17/1.7e-6]); 
% --------------------- %

% Simulation parameters
run_time    = '10800';
mdl         = 'bdot_dynamic_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% Plot Results
bdot_Tps = logsout.getElement('bdot_Tps').Values.Data;
bdot_Tps_time = logsout.getElement('bdot_Tps').Values.Time;

cmd_dipole_Am2 = logsout.getElement('cmd_dipole_Am2').Values.Data;
cmd_dipole_Am2_time = logsout.getElement('cmd_dipole_Am2').Values.Time;

body_rates_radps = logsout.getElement('body_rates_radps').Values.Data;
body_rates_radps_time = logsout.getElement('body_rates_radps').Values.Time;

b_meas_eci_T = logsout.getElement('b_meas_eci_T').Values.Data;
b_meas_eci_time = logsout.getElement('b_meas_eci_T').Values.Time;

figure(1)
subplot(3,1,1)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,1),'r')
subplot(3,1,2)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,2),'b')
ylabel('Commanded Dipole Moment [A m2]','FontSize',12)
subplot(3,1,3)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,3),'k')
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'cmd_dipole_Am2_edit1_png'));
    saveas(gcf, strcat(figdir, 'cmd_dipole_Am2_edit1'),'fig');
end

figure(2)
subplot(3,1,1)
plot(body_rates_radps_time,body_rates_radps(:,1),'r','LineWidth',1)
subplot(3,1,2)
plot(body_rates_radps_time,body_rates_radps(:,2),'b','LineWidth',1)
ylabel('Body Rates [rad/s]','FontSize',12)
subplot(3,1,3)
plot(body_rates_radps_time,body_rates_radps(:,3),'k','LineWidth',1)
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'body_rates_radps_edit1_png'));
    saveas(gcf, strcat(figdir, 'body_rates_radps_edit1'),'fig');
end

figure(3)
plot(bdot_Tps_time,bdot_Tps(:,1),'r')
hold on
plot(bdot_Tps_time,bdot_Tps(:,2),'b')
plot(bdot_Tps_time,bdot_Tps(:,3),'k')
ylabel('$\dot{B}$ [T/s]','FontSize',12)
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'bdot_Tps_edit1_png'));
    saveas(gcf, strcat(figdir, 'bdot_Tps_edit1'),'fig');
end


% b_field     = repmat(sim_params.environment.avg_b,length(b_meas_eci_time),1);
% 
% figure(4), hold on
% plot(b_meas_eci_time,b_meas_eci_T(:,1),'r')
% plot(b_meas_eci_time,b_meas_eci_T(:,2),'b')
% plot(b_meas_eci_time,b_meas_eci_T(:,3),'k')
% %plot(b_meas_eci_time,b_field(:,1),'r','LineWidth',2)
% %plot(b_meas_eci_time,b_field(:,2),'b','LineWidth',2)
% %plot(b_meas_eci_time,b_field(:,3),'k','LineWidth',2)

if save_all == 1
    save(strcat(datadir,'workspace_test1.mat'),'-mat');
end



%% Test 2
fprintf('Press any key to run test 2.\n')
pause

% Testing new gain and cut-off freq in the filter for better performance.

% Initialization
clear varialbes; close all; clc

% Load parameters for both flight software and simulation
fsw_params              = init_fsw_params();
[sim_params,fsw_params] = init_sim_params(fsw_params);

% Change gain
fsw_params.actuators.magnetorquer.max_dipole = 0.25;
fsw_params.control.bdot.gain    =  ...
    - fsw_params.actuators.magnetorquer.max_dipole/5e-6 * eye(3);

% Change cut-off frequency
fsw_params.control.bdot.cutoff_freq = 2*pi*0.1; % [rad/s]

fsw_params.control.bdot.continuous_lpf = ...
    tf([fsw_params.control.bdot.cutoff_freq],...
    [1 fsw_params.control.bdot.cutoff_freq]);

fsw_params.control.bdot.discrete_lpf   = ...
    c2d(fsw_params.control.bdot.continuous_lpf,...
    fsw_params.control.bdot.sample_time_s);

[fsw_params.control.bdot.filter_num,fsw_params.control.bdot.filter_den] = ...
    tfdata(fsw_params.control.bdot.discrete_lpf,'v');

% Extract second component only for use in filter
fsw_params.control.bdot.filter_num     = fsw_params.control.bdot.filter_num(2);
fsw_params.control.bdot.filter_den     = fsw_params.control.bdot.filter_den(2);
% --------------------- %

% Simulation parameters
run_time    = '10800';
mdl         = 'bdot_dynamic_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% % Plot Results
bdot_Tps = logsout.getElement('bdot_Tps').Values.Data;
bdot_Tps_time = logsout.getElement('bdot_Tps').Values.Time;

cmd_dipole_Am2 = logsout.getElement('cmd_dipole_Am2').Values.Data;
cmd_dipole_Am2_time = logsout.getElement('cmd_dipole_Am2').Values.Time;

body_rates_radps = logsout.getElement('body_rates_radps').Values.Data;
body_rates_radps_time = logsout.getElement('body_rates_radps').Values.Time;

figure(1)
subplot(3,1,1)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,1),'r')
subplot(3,1,2)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,2),'b')
ylabel('Commanded Dipole Moment [A m2]','FontSize',12)
subplot(3,1,3)
plot(cmd_dipole_Am2_time,cmd_dipole_Am2(:,3),'k')
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'cmd_dipole_Am2_edit2_png'));
    saveas(gcf, strcat(figdir, 'cmd_dipole_Am2_edit2'),'fig');
end

figure(2)
subplot(3,1,1)
plot(body_rates_radps_time,body_rates_radps(:,1),'r')
subplot(3,1,2)
plot(body_rates_radps_time,body_rates_radps(:,2),'b')
ylabel('Body Rates [rad/s]','FontSize',12)
subplot(3,1,3)
plot(body_rates_radps_time,body_rates_radps(:,3),'k')
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'body_rates_radps_edit2_png'));
    saveas(gcf, strcat(figdir, 'body_rates_radps_edit2'),'fig');
end

figure(3)
plot(bdot_Tps_time,bdot_Tps(:,1),'r')
hold on
plot(bdot_Tps_time,bdot_Tps(:,2),'b')
plot(bdot_Tps_time,bdot_Tps(:,3),'k')
ylabel('$\dot{B}$ [T/s]','FontSize',12)
xlabel('Time [s]','FontSize',12)
if save_all == 1
    SaveFigurePretty(gcf,strcat(figdir,'bdot_Tps_edit2_png'));
    saveas(gcf, strcat(figdir, 'bdot_Tps_edit2'),'fig');
end

if save_all == 1
    save(strcat(datadir,'workspace_test2.mat'),'-mat')
end

%% Tear-down
