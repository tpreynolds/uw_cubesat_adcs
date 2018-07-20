clear all; close all; clc;

f = 1; % Hz (cutoff frequency)
w = 2*pi*f; % rad/s

% Make a LPF
G = tf([w],[1 w]);
bode(G)

% Convert to discrete TF
c2d(G,0.1)

% Take output from c2d() and put coefficients in discrete TF in Simulink 
% model