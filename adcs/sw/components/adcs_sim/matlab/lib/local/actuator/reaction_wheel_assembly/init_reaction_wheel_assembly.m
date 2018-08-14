function reaction_wheel = init_reaction_wheel_assembly
%INIT_RW
%
% Initialize all parameters for the reaction wheel model.
%
% RAIN-SAT -- T. Reynolds 
%   T. Reynolds - 9.23.17

% Model sample time
reaction_wheel.sample_time_s    = (1/20);

% Initial conditions
reaction_wheel.ic.rpm       = zeros(3,1);
reaction_wheel.ic.rt1       = 0;
reaction_wheel.ic.deriv1    = 0;

% Response Characteristics
reaction_wheel.natural_freq     = 10;
reaction_wheel.damping          = 0.8;
reaction_wheel.rate_limit       = 1000;

% Wheel Characteristics
reaction_wheel.max_RPM      = 13500;    % RPM
reaction_wheel.inertia      = 1.788e-06; % kg m^2
reaction_wheel.visc_fric    = 0; % WAG
reaction_wheel.torque_cnst  = 2.34e-3;  % Nm/A WAG
reaction_wheel.delay        = 6.81e-3;  % s WAG
reaction_wheel.resistance   = 1;     % Ohms WAG
reaction_wheel.inductance   = 0.071e-3; % Henry WAG
reaction_wheel.inertia_matrix   = diag([reaction_wheel.inertia,...
                                        reaction_wheel.inertia,...
                                        reaction_wheel.inertia]);

% Motor Characterisitcs
num  = reaction_wheel.torque_cnst;
den  = [reaction_wheel.inertia*reaction_wheel.inductance ...
                        reaction_wheel.inductance*reaction_wheel.visc_fric + reaction_wheel.resistance*reaction_wheel.inertia ...
                        reaction_wheel.resistance*reaction_wheel.visc_fric + reaction_wheel.torque_cnst^2 ];
sys_c   = tf(num,den);
sys_d   = c2d(sys_c,reaction_wheel.sample_time_s); 

reaction_wheel.tf_num   = sys_d.Numerator{1};
reaction_wheel.tf_den   = sys_d.Denominator{1};

% Control Params - tuned with PID tool
reaction_wheel.control.kp    = 0.016443;
reaction_wheel.control.ki    = 0.039012;
reaction_wheel.control.kd    = 0;
reaction_wheel.control.filter_coeff     = 100;
reaction_wheel.control.setpt_weight_b   = 1;
reaction_wheel.control.setpt_weight_c   = 1;