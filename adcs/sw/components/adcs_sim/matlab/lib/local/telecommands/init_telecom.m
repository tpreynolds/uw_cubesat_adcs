function [CAN, fsw_params] = init_CAN( sim_params, fsw_params )
% ----------------------------------------------------------------------- %
%INIT_CAN  Initialize CAN Bus
%
% Initializes all parameters for the CAN bus library used in flight
% software to simulate different signals coming from the rest of the bus.
%
% T. Reynolds -- 1.24.18
% ----------------------------------------------------------------------- %

% Initial conditions
CAN.ic.override                 = 0;
CAN.ic.LowPowerMode             = 0;
CAN.ic.pointing                 = 0;
CAN.ic.sync_pulse_s             = 2;
CAN.ic.MET_epoch                = sim_params.MET.epoch;
CAN.ic.MET                      = 0.0;
CAN.ic.all  = [ CAN.ic.override; 
                CAN.ic.LowPowerMode; 
                CAN.ic.pointing;
                CAN.ic.MET_epoch; 
                CAN.ic.MET ];

% sample the CAN bus at 5 Hz
CAN.sample_time_s   = fsw_params.sample_time_s; 

% Update fsw.bus initial condition
CAN.ic.CAN              = [ CAN.ic.override;
                            CAN.ic.LowPowerMode;
                            CAN.ic.pointing ];

fsw_params.bus.CAN_ic   = [ CAN.ic.override;
                            CAN.ic.LowPowerMode;
                            CAN.ic.pointing ];

% Signal values for simulation
CAN.override                = 0;
CAN.LowPowerMode            = 0;
CAN.pointing                = 1;
CAN.sync_pulse_s            = 2;
CAN.MET_epoch               = sim_params.MET.epoch;

end

