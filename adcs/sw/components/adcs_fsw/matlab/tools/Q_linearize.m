function [ A,B,f ] = Q_linearize( t,x,u,P )
%Q_LINEARIZE    Linearize the attitude dynamics
%
% Q_linearize(P,t,x,u) returns the discrete representation of the
% quaternion-based attitude dynamics at the point (x,u) and time t. The
% struct P must contain at least an entry called 'inertia'.
%
% T. Reynolds -- RAIN Lab.

% States
q   = x(1:4)./norm(x(1:4));
q0  = q(1);
qv  = q(2:4);
w   = x(5:7);
% hw  = x(8:10);

% Constants
J   = P.inertia;

% Partials
dfq_dq  = 0.5 * [ 0 -w'; w -skew(w) ];
dfq_dw  = 0.5 * [ -qv'; skew(qv)+q0*eye(3) ];
dfq_dh  = zeros(4,3);
dfw_dq  = zeros(3,4);
dfw_dw  = -J\( skew(w)*J - skew(J*w) );
dfw_dh  = -J\skew(w);
dfh_dq  = zeros(3,4);
dfh_dw  = zeros(3,3);
dfh_dh  = zeros(3,3);
dfq_du  = zeros(4,3);
dfw_du  = inv(J);
dfh_du  = -eye(3);

% Outputs
f  = Q_ode(P,t,x,u);
A  = [ dfq_dq dfq_dw dfq_dh; 
       dfw_dq dfw_dw dfw_dh; 
       dfh_dq dfh_dw dfh_dh ];
B  = [ dfq_du; dfw_du; dfh_du ];

end