% UW HuskySat-1, ADCS Subsystem
%   Last Updated: T. Reynolds 9.9.17

% Plot Results from a run of sim_init.m
close all

% ----- Extract data ----- %
states = logsout.getElement('states').Values;
    sc_quat = states.quaternion; % [ rad ]
    sc_omega = states.body_rates; % [ rad/s ]
    sc_pos_eci = states.position; % [ m ]
    sc_vel_eci = states.velocity; % [ m\s ]
    
disturbances = logsout.getElement('disturbances').Values;

orbit_data = logsout.getElement('orbit_data').Values;

act_meas = logsout.getElement('act_meas').Values;
    
control = logsout.getElement('control').Values;
    ctrl_RW         = control.torque;
    ctrl_dipole     = control.magnetic_dipole;
sens_meas = logsout.getElement('sens_meas').Values;

commands    = logsout.getElement('commands').Values;

sc_mode = logsout.getElement('sc_mode').Values;

ctrl_status    = logsout.getElement('ctrl_status').Values;

sc_in_sun    = logsout.getElement('sc_in_sun').Values;

sc_in_sun_fsw    = logsout.getElement('sc_in_sun_fsw').Values;

orbit_tle_fsw    = logsout.getElement('orbit_tle_fsw').Values;

cur_gps_time     = logsout.getElement('cur_gps_time').Values;

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
subplot(2,2,2)
plot(sc_omega,'LineWidth',1)
subplot(2,2,3)
plot(sc_pos_eci,'LineWidth',1)
subplot(2,2,4)
plot(sc_vel_eci,'LineWidth',1)

figure(2)
subplot(2,1,1)
plot(ctrl_dipole,'LineWidth',1)
subplot(2,1,2)
plot(ctrl_RW,'LineWidth',1)

figure(3), hold on
plot(sc_mode,'LineWidth',1)
plot(ctrl_status,'LineWidth',1)

REKM = 6378.135; % earth radius [km]
figure(4), hold on
[X, Y, Z]=sphere(100);
X=X.*REKM;
Y=Y.*REKM;
Z=Z.*REKM;
Earth_im = imread('Flat_earth_cds.jpg', 'jpg');
surf(X, Y, Z,'CData',flip(Earth_im,1),'FaceColor','texturemap','EdgeColor','none');
plot3(states.position.Data(:,1)./1e3,states.position.Data(:,2)./1e3,states.position.Data(:,3)./1e3,'r','LineWidth',1)
plot3(true_posx(1:t_end),true_posy(1:t_end),true_posz(1:t_end),'b','LineWidth',1)
%quiver3(0,0,0,avg_sc2sun(1),avg_sc2sun(2),avg_sc2sun(3),'LineWidth',1)
xlabel('x-direction [km]')
ylabel('y-direction [km]')
zlabel('z-direction [km]')
%saveas(gcf, strcat(figdir, 'traj_visualization_test1'),'fig')

% ----- End Plots ----- %