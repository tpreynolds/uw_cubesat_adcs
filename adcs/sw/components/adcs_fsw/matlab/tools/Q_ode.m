function [ dx ] = Q_ode( P,t,x,u,ut )
%Q_ode  Rotational equations of motion with reaction wheels
%
% Q_ode(P,t,x,u) outputs the RHS of the quaternion based attitude
% kinematics and dynamics. It assumes that t is the current time, x is the
% state vector containing:
%   - quaternion: q (4x1)
%   - angular velocity: w (3x1)
%   - wheel momentum: hw (3x1)
% The control input is u (3x1) and P is a set of parameters that 
% must include inertia as P.inertia (3x3) and the discretization method as
% P.method (a string)
% 
% Q_ode(P,t,x,u,ut) takes the vector input of 'control times' ut and
% interpolates the current control u based on the time t. The method is
% assumed to be a first order hold.
%
% T.Reynolds -- RAIN SAT
% States
q   = x(1:4);
q   = q./norm(q);
q0  = q(1);
qv  = q(2:4);
w   = x(5:7);
hw  = x(8:10);

% Get control
if( nargin < 5 )
    uu = u;
else
    uu = interp1(ut,u',t,P.method)';
end
    
% Kinematics
dq  = 0.5 * [ -qv'; skew(qv)+q0*eye(3) ] * w;
% Dynamics
dw  = P.inertia\( - uu - skew(w) * (P.inertia*w + hw) );
% Wheel momentum
dh  = uu;

% Output
dx  = [ dq; dw; dh ];

end

