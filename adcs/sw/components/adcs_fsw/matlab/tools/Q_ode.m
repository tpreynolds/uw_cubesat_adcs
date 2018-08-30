function [ dx ] = Q_ode( P,t,x,u,ut )
%F_ROT  Rotational equations of motion
%
% f_rot(P,t,x,u) outputs the RHS of the quaternion based attitude
% kinematics and dynamics. It assumes that t is the current time, x is the
% state vector containing q (4x1) and w (3x1). u is the control input, a
% 3x1 vector, and P is a set of parameters (must include inertia). The
% 
% f_rot(P,t,x,u,ut) takes the vector input of 'control times' ut and
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

% Get control
if( nargin < 5 )
    uu = u;
else
    uu = interp1(ut,u',t,P.method)';
end
    
% Kinematics
dq  = 0.5*[ -dot(qv,w); (q0*eye(3)+skew(qv))*w ];
% Dynamics
dw  = P.inertia\(uu - skew(w)*P.inertia*w);

% Output
dx  = [ dq; dw ];

end

