function [ A,B,f ] = Q_linearize_p( t,x,u,P )
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
hb  = x(5:7);
hw  = x(8:10);

% Constants
J   = P.inertia;
w   = J\hb;

% Partials
dfq_dq   = 0.5 * [ 0 -w'; w -skew(w) ];
dfq_dhb  = 0.5 * [ -qv'; skew(qv)+q0*eye(3) ]/J;
dfq_dhw  = zeros(4,3);
dfhb_dq  = zeros(3,4);
dfhb_dhb = skew(hb)/J - skew(w) + skew(hw)/J;
dfhb_dhw = -skew(w);
dfhw_dq  = zeros(3,4);
dfhw_dhb = zeros(3,3);
dfhw_dhw = zeros(3,3);
dfq_du   = zeros(4,3);
dfhb_du  = -eye(3);
dfhw_du  = eye(3);

% Outputs
f  = Q_ode_p(P,t,x,u);
A  = [ dfq_dq  dfq_dhb  dfq_dhw; 
       dfhb_dq dfhb_dhb dfhb_dhw; 
       dfhw_dq dfhw_dhb dfhw_dhw ];
B  = [ dfq_du; dfhb_du; dfhw_du ];

end