% UW HuskySat-1, ADCS Subsystem
%   Last Updated: T. Reynolds 12.28.17

% Plot Results from a run of sim_init.m
close all
set(0,'defaulttextinterpreter','latex')

% ----- Extract data ----- %
states_plot = logsout.getElement('states').Values;
    sc_quat = states_plot.quaternion; % [ rad ]
    sc_omega = states_plot.body_rates; % [ rad/s ]
    sc_pos_eci = states_plot.position; % [ m ]
    sc_vel_eci = states_plot.velocity; % [ m\s ]
    
%disturbances_plot = logsout.getElement('disturbances').Values;

%orbit_data_plot = logsout.getElement('orbit_data').Values;

act_meas = logsout.getElement('act_meas').Values;
    
control_plot = logsout.getElement('control').Values;
    ctrl_RW         = control_plot.torque;
    ctrl_dipole     = control_plot.magnetic_dipole;
sens_meas_plot = logsout.getElement('sens_meas').Values;

commands_plot = logsout.getElement('commands').Values;

sc_mode_plot = logsout.getElement('sc_mode').Values;

ctrl_status_plot    = logsout.getElement('ctrl_status').Values;

sc_in_sun_plot    = logsout.getElement('sc_in_sun').Values;

sc_in_sun_fsw_plot    = logsout.getElement('sc_in_sun_fsw').Values;

orbit_tle_fsw_plot    = logsout.getElement('orbit_tle_fsw').Values;

cur_gps_time_plot     = logsout.getElement('cur_gps_time').Values;

% ----- End extract ----- % 


% Load other data
filename    = sim_params.environment.sgp4.tle_filename;
num = length(filename);
if num == 12
    load('QUAKESAT_data.mat');
    true_posx = QUAKESAT_data{1};
    true_posy = QUAKESAT_data{2};
    true_posz = QUAKESAT_data{3};
else
    load('SWISSCUBE_data.mat');
    true_posx = SWISSCUBE_data{1};
    true_posy = SWISSCUBE_data{2};
    true_posz = SWISSCUBE_data{3};
end
t_end = str2double(run_time);


% ---- Plot Results ---- %
figure(1)
subplot(2,2,1)
plot(sc_quat,'LineWidth',1)
xlabel('Time [s]')
title('Spacecraft Quaternion','Fontsize',15)
subplot(2,2,2)
plot(sc_omega,'LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity','Fontsize',15)
subplot(2,2,3)
plot(sc_pos_eci,'LineWidth',1)
xlabel('Time [s]')
title('Inertial Position','Fontsize',15)
subplot(2,2,4)
plot(sc_vel_eci,'LineWidth',1)
xlabel('Time [s]')
title('Inertial Velocity','Fontsize',15)

figure(2)
subplot(2,1,1)
plot(ctrl_dipole,'LineWidth',1)
title('Commanded Magnetorquer Dipole','FontSize',15)
subplot(2,1,2)
plot(ctrl_RW,'LineWidth',1)
title('Commanded Reaction Wheel RPM','FontSize',15)

figure(3), hold on
plot(sc_mode_plot,'LineWidth',1)
plot(ctrl_status_plot,'LineWidth',1)
legend('ADCS Mode','Control Mode')
xlabel('Time [s]','FontSize',14)
title('ADCS Mode and Control Mode','FontSize',15)

REKM = 6378.135; % earth radius [km]
figure(4), hold on
[X, Y, Z]=sphere(100);
X=X.*REKM;
Y=Y.*REKM;
Z=Z.*REKM;
Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
surf(X, Y, Z,'CData',flip(Earth_im,1),'FaceColor','texturemap','EdgeColor','none');
plot3(states_plot.position.Data(:,1)./1e3,states_plot.position.Data(:,2)./1e3,states_plot.position.Data(:,3)./1e3,'r','LineWidth',1)
plot3(true_posx(1:t_end),true_posy(1:t_end),true_posz(1:t_end),'b','LineWidth',1)
%quiver3(0,0,0,avg_sc2sun(1),avg_sc2sun(2),avg_sc2sun(3),'LineWidth',1)
xlabel('x-direction [km]')
ylabel('y-direction [km]')
zlabel('z-direction [km]')
%saveas(gcf, strcat(figdir, 'traj_visualization_test1'),'fig')

% ----- End Plots ----- %