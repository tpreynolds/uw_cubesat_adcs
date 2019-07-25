function rwa = init_reaction_wheel_assembly(fsw_params)
%INIT_RW
%
% Initialize all parameters for the reaction wheel model.
%
% RAIN-SAT -- T. Reynolds 
%   T. Reynolds - 9.23.17

rwa.num_wheels = 4;

% Model sample time
rwa.sample_time_s    = (1/20);

% Wheel Characteristics
rwa.max_RPM      = 10000;       % RPM
rwa.inertia      = 2e-6;   % kg m^2
rwa.visc_fric    = 1e-6;        % WAG
rwa.torque_cnst  = 1e-3;     % Nm/A WAG
rwa.delay        = 0;%6.81e-3;     % s WAG
rwa.resistance   = 1;           % Ohms WAG
rwa.inductance   = 1e-6;%0.071e-3;    % Henry WAG
rwa.inertia_matrix   = rwa.inertia * eye(rwa.num_wheels);
rwa.inv_inertia_matrix = inv(rwa.inertia_matrix);
rwa.dc_voltage   = 5; % V
rwa.cant_angle   = 23 * fsw_params.constants.convert.deg2rad; % rad

% torque allocation matrix
cb = cos(rwa.cant_angle);
sb = sin(rwa.cant_angle);
rwa.Aw = [ cb 0.0 -cb 0.0;
           0.0 cb 0.0 -cb;
           sb sb sb sb;
           1 -1 1 -1];
rwa.iAw = inv(rwa.Aw);

% Initial conditions
rwa.ic.rpm       = zeros(rwa.num_wheels,1);
rwa.ic.momentum  = rwa.inertia_matrix ...
                    * (fsw_params.constants.convert.RPM_2_radps * rwa.ic.rpm);
body_momentum = rwa.Aw * rwa.ic.momentum; % about body axes
rwa.ic.body_momentum = body_momentum(1:3);
rwa.ic.power_W   = zeros(rwa.num_wheels,1);
rwa.ic.torque_Nm = zeros(rwa.num_wheels,1); % about wheel axes
body_torque_Nm = rwa.Aw * rwa.ic.torque_Nm;
rwa.ic.body_torque_Nm = body_torque_Nm(1:3); % about body axes
rwa.ic.rt1       = 0;
rwa.ic.deriv1    = 0;

% Approximated response characterisic
rwa.dOmega_max       = 3 * fsw_params.constants.convert.radps_2_RPM * ...
    fsw_params.bus.max_torque * rwa.sample_time_s / rwa.inertia;

% Motor Characterisitcs
num  = rwa.torque_cnst;
den  = [ rwa.inertia*rwa.inductance ...
         rwa.inductance*rwa.visc_fric + rwa.resistance*rwa.inertia ...
         rwa.resistance*rwa.visc_fric + rwa.torque_cnst^2 ];
num2  = [ rwa.inertia rwa.visc_fric ];
                    
sys_c  = tf(num,den); % TF for V to Omega
sys_c2 = tf(num2,den); % TF for V to I
sys_d  = c2d(sys_c,rwa.sample_time_s); 
sys_d2 = c2d(sys_c2,rwa.sample_time_s); 

rwa.tf_num   = sys_d.Numerator{1};
rwa.tf_den   = sys_d.Denominator{1};
rwa.tf_V2I_num = sys_d2.Numerator{1};
rwa.tf_V2I_den = sys_d2.Denominator{1};

% Control Params - tuned with PID tool
rwa.control.kp    = 0.016443;
rwa.control.ki    = 0.039012;
rwa.control.kd    = 0;
rwa.control.filter_coeff     = 100;
rwa.control.setpt_weight_b   = 1;
rwa.control.setpt_weight_c   = 1;