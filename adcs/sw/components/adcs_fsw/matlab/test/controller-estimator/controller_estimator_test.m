% run sim init before starting this script
clc; close all;
set(0,'defaulttextinterpreter','latex');
cd /media/sexymathemagician/LaCie1/uw_cubesat_adcs/adcs/sw/components/adcs_fsw/matlab/test/controller-estimator/
addpath(genpath(pwd))

rng(155);

figdir = strcat(pwd,'/figs/');
datadir = strcat(pwd,'/data/');



run_time    = '50';
mdl         = 'controller_estimator_test';
load_system(mdl);
set_param(mdl, 'StopTime', run_time);
sim(mdl);
