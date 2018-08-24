function MPCobj = matlab_lmpc(x0, J, Delta, Hp, Hc)

Nx = length(x0);
A = getJacobian(x0);

% Linearized model
J_inv = inv(J);
Bd = Delta*[zeros(4,3); J_inv];
Ad = Delta*A + eye(Nx);
Cd = eye(Nx);
Dd = zeros(7,3);


plant = ss(Ad,Bd,Cd,Dd,Delta);


MPCobj = mpc(plant, Delta, Hp, Hc);

% Disbable properties of MPC
MPCobj.Weights.MVRate = zeros(1,3);
setoutdist(MPCobj,'Model',tf(zeros(Nx,1)))
setEstimator(MPCobj,'custom')