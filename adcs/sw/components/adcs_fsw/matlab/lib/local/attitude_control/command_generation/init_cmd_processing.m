function [ cmd_processing ] = init_cmd_processing(fsw_params)
% ----------------------------------------------------------------------- %
%INIT_CMD_PROCESSING
%
%   Parameters used in command processing library.
%
% RAIN-SAT -- T. Reynolds 7.7.18
% ----------------------------------------------------------------------- %

% Initial conditions
cmd_processing.ic.momentum = ...
                   fsw_params.actuators.reaction_wheel.inertia_matrix * ...
                        (fsw_params.actuators.ic.RW_RPM * ...
                            fsw_params.constants.convert.RPM_2_radps);

% Digital value range
DV    = fsw_params.constants.dig_val;

% Gains
cmd_processing.dv_2_m_X   = ...
                   fsw_params.actuators.magnetorquer.max_dipole_x / DV;
cmd_processing.m_2_dv_X   = 1/cmd_processing.dv_2_m_X;

cmd_processing.dv_2_m_Y   = ...
                   fsw_params.actuators.magnetorquer.max_dipole_y / DV;
cmd_processing.m_2_dv_Y   = 1/cmd_processing.dv_2_m_Y;

cmd_processing.dv_2_m_Z   = ...
                    fsw_params.actuators.magnetorquer.max_dipole_z / DV;
cmd_processing.m_2_dv_Z   = 1/cmd_processing.dv_2_m_Z;

% Invalid input
cmd_processing.invalid_input = int8(zeros(3,1));
end

