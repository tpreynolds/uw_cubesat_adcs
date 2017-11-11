function MPCobj = init_matlab_test(compile)

% Quaternion-based MPC attitude control.

% UW HuskySat-1, ADCS Subsystem
% Updated: B. Barzgaran 11.3.17

% This script sets up a test of the matlab mpc toolbox.
% Initializes all parameters and control objects necessary for basic tests.
% Run before executing matlab_test.

clear; clc; close all;

if ~exist('compile','var')
    compile = false;
end

% Initialization 
% Spacecraft Parameters 
Delta   = 0.5;
Nx      = 7;
Nu      = 3;
Nsim    = 100;
a = 0.1; % length of side (m)
b = 0.1; % length of side (m)
c = 0.3; % spacecraft height (m)
m = 5; % spacecraft mass (kg)
% Moments of Inertia of rectangular parallelepiped (kg-m^2)
J_xx = 1/12*m*(a^2+c^2);
J_yy = 1/12*m*(b^2+c^2);
J_zz = 1/12*m*(a^2+b^2);
J = diag([J_xx J_yy J_zz]);

% Initial Conditions
w0 = [0.003 -0.002 0.001]'; % Initial Angular velocity of B wrt I (rad/s)
eig_axis = [1;0;0];
%eig_axis = eig_axis./norm(eig_axis);
angle   = 25;
q0 = [cos(angle*pi/180); sin(angle*pi/180)*eig_axis ]; % Initial quaternion
x0 = [q0; w0];

% Desired quaternion
qd  = [1 0 0 0]';
wd  = [0 0 0]';
x_d    = [wd; 0];

% Control Parameters
N   = 20;
u_max   = 1e-3;
w_max   = 0.075;
Q   = [25*ones(4,1);50*ones(3,1)];
Qf  = [100*ones(4,1);1*ones(3,1)];
R   = ones(3,1);  

%% Constrained Cone
% Taylor's code
% Build Constraint
theta   = 60;   % deg
r   = [0 0 1]'; % Inertial vector
% DCM     = quat2dcm(q0');
% v   = DCM*r; % Body vector
% v   = v(1:3);
% r_skew  = skew(r);
% ctht    = cosd(theta);
% mat     = r*v' + v*r' - (r'*v+ctht)*eye(3);
% M   = [r'*v-ctht v'*r_skew;    
%         -r_skew*v  mat];
    
%     u_max   = 1e-3;
%     w_max   = 0.075;

%% Pyramid relaxation

% orthogonal vectors (better method to verify direction)
Z = null(r');
p1 = Z(:,1);
p2 = Z(:,2);

% rotate both vectors about the other with half cone angle
p1r = [p1; theta/2]; M1r = vrrotvec2mat(p1r);
p2r = [p2; theta/2]; M2r = vrrotvec2mat(p2r);
p3r = [p1; -theta/2]; M3r = vrrotvec2mat(p3r);
p4r = [p2; -theta/2]; M4r = vrrotvec2mat(p4r);

% check directions
r1 = M2r*p1;
r2 = M1r*p2;
r3 = -M3r*p1;
r4 = -M4r*p2;

RM = [r1'; r2'; r3'; r4'];

%% MPC toolbox
% Control Object
MPCobj = matlab_lmpc(x0, J, Delta, N, N);

MPCobj.Weights.MV = sqrt(R');
%MPCobj.Weights.MVRate
MPCobj.Weights.OV = sqrt(Q');
% % Terminal weight
% Qnt = repmat(Q',N-1,1);
% MPCobj.weights.OV = [Qnt;Qf];


%% Compiling Code
if compile
    [configData,stateData,onlineData] = getCodeGenerationData(MPCobj);
    stateData.Plant = x0;

    func = 'mpcmoveCodeGeneration';
    funcOutput = 'mpcSimCS';
    Cfg = coder.config('lib');
    Cfg.DynamicMemoryAllocation = 'off';
    codegen('-config',Cfg,func,'-o',funcOutput,'-args',...
        {coder.Constant(configData),stateData,onlineData});
end

