function [ MET,fsw_params ] = init_MET( fsw_params )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
% 
% Initializes the Mission Elapsed Time library.
%
% T.Reynolds -- 3.9.18
% ----------------------------------------------------------------------- %

MET.res     = 1e-8; %resolution
MET.epoch   = fsw_params.constants.ic.time.JD_J2000_TT_s;
fsw_params.bus.MET_epoch    = MET.epoch;

end

