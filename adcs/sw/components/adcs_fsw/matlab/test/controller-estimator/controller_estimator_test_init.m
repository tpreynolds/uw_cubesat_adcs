%% EKF Estimator Test
% Test 1:
%   Provide static inertial vectors and random initial estimator states.
%   The controller should steer the estimated state the (static) commanded
%   state. Required estimator convergencence in under 60s.

% UW HuskySat-1, ADCS Subsystem
%  Primary: M. Hudoba de Badyn -- x.x.xx
%   Secondary: T. Reynolds -- 3.6.18

% Note: Assumes sim_init.m has been run
clc; close all;
set(0,'defaulttextinterpreter','latex');
%% Test 1

% seed the random initial conditions so you get the same stuff everytime
rng(155);

% Attitude conditions
quat_cmd = [0.5; 0.5; 0.5; 0.5];%-[-0.1; 0.2; 0.3; 0.4];
quat_cmd = quat_cmd/norm(quat_cmd);

% Angular velocity
sim_params.dynamics.ic.rate_init = 0*[0.1 -0.05 -0.03]';

% Run the test
run_time    = '200';
mdl         = 'controller_estimator_test_static';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);

% Plot results
h1 = figure;
plot(omega_hat.Time, omega_hat.Data(:,1),'r--'), hold on
plot(omega_hat.Time, omega_hat.Data(:,2),'b--')
plot(omega_hat.Time, omega_hat.Data(:,3),'k--')
plot(omega_true.Time, omega_true.Data(:,1),'r')
plot(omega_true.Time, omega_true.Data(:,2),'b')
plot(omega_true.Time, omega_true.Data(:,3),'k')

h2 = figure;
plot(quat_hat.Time, quat_hat.Data(:,1),'r--'), hold on
plot(quat_hat.Time, quat_hat.Data(:,2),'b--')
plot(quat_hat.Time, quat_hat.Data(:,3),'k--')
plot(quat_hat.Time, quat_hat.Data(:,4),'g--')
plot(quat_true.Time, quat_true.Data(:,1),'r')
plot(quat_true.Time, quat_true.Data(:,2),'b')
plot(quat_true.Time, quat_true.Data(:,3),'k')
plot(quat_true.Time, quat_true.Data(:,4),'g')
plot(quat_true.Time, quat_cmd(1)*ones(size(quat_true.Time)), 'k','linewidth',2)
plot(quat_true.Time, quat_cmd(2)*ones(size(quat_true.Time)), 'k','linewidth',2)
plot(quat_true.Time, quat_cmd(3)*ones(size(quat_true.Time)), 'k','linewidth',2)
plot(quat_true.Time, quat_cmd(4)*ones(size(quat_true.Time)), 'k','linewidth',2)

h3 = figure;
plot(bias_hat)

