function mode_selection = init_mode_selection(fsw_params)
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%
% Initializes data for target generation library
%
% T. Reynolds 2.17.18
% ----------------------------------------------------------------------- %

mode_selection.sample_time_s    = fsw_params.sample_time_s;

% Initial rate transition conditions 
mode_selection.ic.sc_mode   = 1;


end