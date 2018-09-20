function [ A,B,f ] = Q_linearize( t,x,u,P )
%Q_LINEARIZE    Linearize the attitude dynamics
%
% Q_linearize(P,t,x,u) returns the discrete representation of the
% quaternion-based attitude dynamics at the point (x,u) and time t. The
% struct P must contain at least an entry called 'inertia'.
%
% T. Reynolds -- RAIN Lab.

% States
q   = x(1:4);%./norm(x(1:4));
q0  = q(1);
qv  = q(2:4);
w   = x(5:7);

% Constants
J   = P.inertia;

% Partials
dfq_dq  = 0.5 * [ 0 -w'; w -skew(w) ];
dfq_dw  = 0.5 * [ -qv'; skew(qv)+q0*eye(3) ];
dfw_dq  = zeros(3,4);
dfw_dw  = -J\( skew(w)*J - skew(J*w) );
dfq_du  = zeros(4,3);
dfw_du  = inv(J);

% Outputs
f  = Q_ode(P,t,x,u);
A  = [ dfq_dq dfq_dw; dfw_dq dfw_dw ];
B  = [ dfq_du; dfw_du ];

end