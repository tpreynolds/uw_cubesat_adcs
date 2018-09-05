function [telecom, fsw_params] = init_telecom( sim_params, fsw_params )
% ----------------------------------------------------------------------- %
%INIT_TELECOM   Initialize Telecommands Bus
%
% Initializes all parameters for the telecommand library used in flight
% software to simulate different signals coming from the rest of the bus.
%
% T. Reynolds -- 1.24.18
% ----------------------------------------------------------------------- %

% Initial conditions
telecom.ic.override                 = 0;
telecom.ic.LowPowerMode             = 0;
telecom.ic.pointing                 = 0;
telecom.ic.sync_pulse_s             = 2;
telecom.ic.MET_epoch                = sim_params.MET.epoch;
telecom.ic.MET                      = 0.0;
telecom.ic.all  = [ telecom.ic.override;
                    telecom.ic.LowPowerMode;
                    telecom.ic.pointing;
                    telecom.ic.MET_epoch;
                    telecom.ic.MET ];
                
telecom.ic.telecom  = [ telecom.ic.override;
                        telecom.ic.LowPowerMode;
                        telecom.ic.pointing ];

% Sample rate
telecom.sample_time_s   = fsw_params.sample_time_s; 

% Signal values for simulation
telecom.override                = 0;
telecom.LowPowerMode            = 0;
telecom.pointing                = 1;
telecom.sync_pulse_s            = 2;
telecom.MET_epoch               = sim_params.MET.epoch;

% Update fsw params
fsw_params.bus.telecom_ic = [ telecom.ic.override;
                                telecom.ic.LowPowerMode;
                                telecom.ic.pointing ];
fsw_params.bus.sync_pulse_s     = telecom.sync_pulse_s;

end

