function CAN = init_CAN( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes all parameters for the CAN bus library used in flight
% software to simulate different signals coming from the rest of the bus.
%
%   Last Edited: T. Reynolds, 11.11.17
% ----------------------------------------------------------------------- %

CAN.override     = 31;
CAN.reboot       = 0;
CAN.pointing     = 1;
CAN.COM2_on      = 1;
CAN.adcs_experimental        = 0;
CAN.adcs_experimental_type   = 1;
CAN.sync_pulse_period_s      = 2;
CAN.PPT_on_sync_pct          = 60;


end

