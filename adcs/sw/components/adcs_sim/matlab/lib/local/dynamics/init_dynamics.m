function [dynamics,fsw_params] = init_dynamics(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_DYNAMICS      Dynamics Init File for SIM
%
% Initializes the dynamics block used in SIM. Quaternions are scalar first
% as per Matlab convention.
%
% T. Reynolds, 11.12.17
% ----------------------------------------------------------------------- %

% Initial Conditions
temp                    = randn(4,1);
dynamics.ic.quat_init   = temp./norm(temp);
dynamics.ic.quat_init   = [1 0 0 0]'; % override random starting condition
dynamics.ic.rate_init   = [0 0 0]';

% Update FSW struct
fsw_params.control.pd_controller.ic.torque = ...
                              fsw_params.bus.inertia*dynamics.ic.rate_init;

end