%% Init Sim Magnetorquer Model
%   HuskySat-1, ADCS Subsystem
%   T. Reynolds - 5.27.17

%%
function magnetic     = init_magnetic_field

magnetic.dec_year_subtract  = 1; % Subtract from the decimal year for use in WMM
magnetic.nT_2_T     = 1/1e9; % Conversion factor
