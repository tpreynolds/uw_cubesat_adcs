function pd_controller = init_pd_controller( )
% ----------------------------------------------------------------------- %
% UW HuskySat-1, ADCS Team
%   Load the parameters for the PD reorientation controller. Any block used
%   in the controller should be initialized here. 
% Last Edited: T. Reynolds 6.23.17
% ----------------------------------------------------------------------- %

% Initial Conditions

% PD Controller gains
pd_controller.p_gain = -1;
pd_controller.d_gain = -1;


