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
CAN.ic.actuators_on             = 0;
CAN.ic.control_type             = 0;
CAN.ic.sync_pulse_period_s      = 2;
CAN.ic.PPT_on_sync_pct          = 60;
CAN.ic.MET_epoch                = sim_params.MET.epoch;
CAN.ic.all  = [ CAN.ic.override; CAN.ic.LowPowerMode; CAN.ic.pointing;
                CAN.ic.control_type; CAN.ic.MET_epoch; 0.0 ];

% sample the CAN bus at 5 Hz
CAN.sample_time_s   = 1/5; 

% Update fsw.bus initial condition
CAN.ic.all              = [ CAN.ic.override;
                            CAN.ic.LowPowerMode;
                            CAN.ic.pointing;
                            CAN.ic.control_type ];

fsw_params.bus.CAN_ic   = [ CAN.ic.override;
                            CAN.ic.LowPowerMode;
                            CAN.ic.pointing;
                            CAN.ic.control_type ];


% Signal values for simulation
CAN.override                = 0;
CAN.LowPowerMode            = 0;
CAN.pointing                = 1;
CAN.actuators_on            = 1;
CAN.control_type            = 1;
CAN.MET_epoch               = sim_params.MET.epoch;
CAN.sync_pulse_period_s     = 2;
CAN.PPT_on_sync_pct         = 60;


end

