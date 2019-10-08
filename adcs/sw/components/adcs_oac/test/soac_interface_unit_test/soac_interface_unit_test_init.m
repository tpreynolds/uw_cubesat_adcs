% Unit test file for GNC-2 interface library
%
% T. Reynolds -- RAIN Lab

rng(2) % for repeatability of random IC

% constants
w_max   = soac_params.w_max;
T_max   = soac_params.T_max;
hw_max  = [ 37; 37; 31.3 ] * 1e-3; % Nms
Jw      = sim_params.actuators.reaction_wheel.inertia_matrix;
Aw      = sim_params.actuators.reaction_wheel.Aw;
J       = soac_params.inertia;
RPM2RADPS = fsw_params.constants.convert.RPM_2_radps;
sc_mode   = 33;
GPS_epoch = sim_params.environment.sgp4.gps_time; % epoch and GPS time

% initial conditions
ax       = [0.72756;0.027687;0.68549];
ax       = ax./norm(ax);
ang      = 38.667;
quat_in  = [0.92608;0.20851;-0.0048867;-0.31446];%[ cosd(ang/2); sind(ang/2).*ax ];
omega_in = [0.00012082;0.00014607;0.021011];
Om0      = [ 905.63; -1062.5; 988.37; -992 ];    % initial wheel RPM
hw0      = Aw * Jw * (RPM2RADPS * Om0);     % initial wheel momentum
hw_in    = [2.1259e-6;5.8341e-6;-8.6055e-7];%horzcat(eye(3),zeros(3,1)) * hw0;

% overwrite internal parameters for the simulation
sim_params.dynamics.ic.quat_init                = quat_in;
sim_params.dynamics.ic.rate_init                = omega_in;
sim_params.actuators.reaction_wheel.ic.rpm      = Om0;
fsw_params.control.cmd_processing.ic.momentum   = hw0;

% final conditions
q_err       = [ cosd(2/2); sind(2/2).*ax ];
quat_cmd    = [1.0;0.0;0.0;0.0];%quatmultiply(q_err',quat_in')';%[ 1.0; 0.0; 0.0; 0.0 ];
omega_cmd   = [ 0.0; 0.0; 0.0 ];

% inertial sun vector
sI_unit  = [ 1.0; 0.0; 0.0 ];

% Load sim and set run time
run_time    = 60;%soac_params.s_max;
mdl         = 'soac_interface_unit_test';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));

% run test case
sim(mdl);

%% analyze results

% write input file
filename = strcat('soac_interface_test_inputs','_',num2str(1/soac_params.sample_time_s),'Hz','.txt');
flag = write_testinput_file(filename,...
            sc_mode_.Data,quat_in_.Data,omega_in_.Data,hw_in_.Data,...
            quat_cmd_.Data,omega_cmd_.Data,sI_unit_.Data,...
            GPS_epoch_.Data,GPS_time_.Data);

u_opt = command_torque;
x_opt = command_state;

xf = x_opt(end,:);
qf = xf(1:4);
wf = xf(5:7);
hwf = xf(8:10);

% Plot
close all
figure
subplot(3,1,1), hold on, grid on
plot(tout,x_opt(:,1),'LineWidth',1)
plot(tout,sc_quat(:,1),'LineWidth',1)
xlabel('Time [s]')
title('Attitude Quaternion (Scalar part)')
legend('Commanded','Realized')
subplot(3,1,2), hold on, grid on
plot(tout,x_opt(:,5),'LineWidth',1)
plot(tout,body_rates_radps(:,1),'LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity (x axis only)')
legend('Commanded','Realized')
subplot(3,1,3), hold on, grid on
plot(tout,x_opt(:,8:10),'LineWidth',1)
xlabel('Time [s]')
title('Commanded Wheel Momentum')

figure, hold on, grid on
plot(tout,u_opt,'LineWidth',1)
xlabel('Time [s]')
title('Feedforward Control Signal')

for k = 1:length(x_opt)
    qk = x_opt(k,1:4);
    q_err = quatmultiply(quatconj(qk),quat_cmd')';
    deg_err(k) = real(2*acosd(q_err(1)));
end
figure, hold on, grid on, box on
plot(tout,deg_err,'LineWidth',1)


