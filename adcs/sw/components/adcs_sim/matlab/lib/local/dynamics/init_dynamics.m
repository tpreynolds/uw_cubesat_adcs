function dynamics = init_dynamics(fsw_params)
% UW Husky-Sat 1, ADCS Team

% Initializes the dynamics block used in SIM. Quaternions are scalar first
% as per Matlab convention.

% Last Update: T. Reynolds, 11.12.17

% Quaternion FIRST
temp    = randn(4,1);
dynamics.ic.quat_init = temp./norm(temp);
dynamics.ic.quat_init = [1 0 0 0]'; % override random starting condition
dynamics.ic.rate_init = [0.1 0.1 0.1]';

fsw_params.control.pd_controller.ic.torque = fsw_params.bus.inertia*dynamics.ic.rate_init;

end