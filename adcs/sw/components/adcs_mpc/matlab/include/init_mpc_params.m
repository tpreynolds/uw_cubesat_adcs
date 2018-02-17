function mpc = init_mpc_params(fsw_params)

mpc.lin = init_mpc_linearization();

Delta = 0.1;

% Linearization
XIq     = [ q(1) -q(2)  q(3);
            q(2)  q(1) -q(4);
           -q(3)  q(4)  q(1);
           -q(2) -q(3) -q(4) ];

XIw     = [  0   -w(1)  w(2)  w(1);
            w(1)   0   -w(3)  w(2);
           -w(2)  w(3)   0    w(3);
           -w(1) -w(2) -w(3)   0  ];

A = [ 0.5*XIw 0.5*XIq;
        zeros(3,4) zeros(3,3) ];

J = fsw_params.bus.inertia;
J_inv = inv(J);
B = [zeros(4,3); J_inv];
C = eye(Nx);
D = zeros(7,3);

plant = ss(A,B,C,D,Delta);

Hp = 10;
Hc = 2;

MPCobj = mpc(plant, Delta, Hp, Hc);

% Weights
Q   = [25*ones(4,1);50*ones(3,1)];
R   = ones(3,1);  

MPCobj.Weights.MV = sqrt(R');
%MPCobj.Weights.MVRate
MPCobj.Weights.OV = sqrt(Q');
% % Terminal weight
% Qnt = repmat(Q',N-1,1);
% MPCobj.weights.OV = [Qnt;Qf];

% Disable properties of MPC
MPCobj.Weights.MVRate = zeros(1,3);
setoutdist(MPCobj,'Model',tf(zeros(Nx,1)))
setEstimator(MPCobj,'custom')

mpc.MPCobj = MPCobj;
mpc. Delta = Delta;
% mpc.ic_state = 