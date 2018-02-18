function CAN = init_CAN( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all parameters for the CAN bus library used in flight
% software to simulate different signals coming from the rest of the bus.
%
%   Last Edited: T. Reynolds, 1.24.18
% ----------------------------------------------------------------------- %

CAN.sample_time_s   = 1/5;  % sample the CAN bus at 5 Hz

CAN.override     = 0;
CAN.LowPowerMode = 0;
CAN.pointing     = 1;
CAN.COM2_on      = 1;
CAN.adcs_experimental        = 0;
CAN.adcs_experimental_type   = 1;
CAN.sync_pulse_period_s      = 2;
CAN.PPT_on_sync_pct          = 60;


end

