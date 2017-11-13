function dynamics = init_dynamics()
% UW Husky-Sat 1, ADCS Team

% Initializes the dynamics block used in SIM. Quaternions are scalar first
% as per Matlab convention.

% Last Update: T. Reynolds, 8.3.17

% Quaternion FIRST
temp    = randn(4,1);
dynamics.ic.quat_init = temp./norm(temp);
dynamics.ic.quat_init = [1 0 0 0]';
dynamics.ic.rate_init = [0.2 0.2 0.2]';