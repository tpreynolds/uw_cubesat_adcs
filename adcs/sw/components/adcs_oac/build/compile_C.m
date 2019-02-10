% Convex optimization call is written with the C API for the ECOS solver
% This file converts this C code to a MEX file for use in Simulink as an 
% S-function.

% Run this file from the BUILD directory

%% Compilation parameters
def = legacy_code('initialize');
def.SFunctionName = 'sfun_ecos';
def.IncPaths = {'../include/ecos/include'};
def.SrcPaths = {'../include/ecos/src'};
def.SourceFiles = {'matlab_main.c','cone.c','ctrlc.c','ecos.c',...
                   'equil.c','expcone.c','kkt.c','preproc.c','spla.c',...
                   'splamm.c','timer.c','wright_omega.c','ldl.c','amd_1.c',...
                   'amd_2.c','amd_aat.c','amd_control.c','amd_defaults.c',...
                   'amd_dump.c','amd_global.c','amd_info.c','amd_order.c',...
                   'amd_post_tree.c','amd_postorder.c','amd_preprocess.c','amd_valid.c'};
def.HeaderFiles = {'ecos.h'};
def.OutputFcnSpec = ['callecos('...
                     'int32 u1,'...                          % int n
                     'int32 u2,'...                          % int m
                     'int32 u3,'...                          % int p
                     'int32 u4,'...                          % int l
                     'int32 u5,'...                          % int ncones
                     'double u6[' num2str(c_size) '],'...    % double *c
                     'int32 u7[' num2str(Gjc_size) '],'...   % double *Gjc
                     'int32 u8[' num2str(Gir_size) '],'...   % double *Gir
                     'double u9[' num2str(Gpr_size) '],'...  % double *Gpr
                     'double u10[' num2str(h_size) '],'...   % double *h
                     'int32 u11[' num2str(q_size) '],'...    % int *q
                     'int32 u12[' num2str(Ajc_size) '],'...  % int *Ajc
                     'int32 u13[' num2str(Air_size) '],'...  % int *Air
                     'double u14[' num2str(Apr_size) '],'... % double *Apr
                     'double u15[' num2str(b_size) '],'...   % double *b
                     'double y1[' num2str(y_size) '])'];     % double *y

%% Compile MEX
legacy_code('generate_for_sim',def);