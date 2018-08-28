function [ At,Bt,zt ] = Q_linearize( P,t,x,u )
%Q_LINEARIZE    Linearize the attitude dynamics
%
% Q_linearize(P,t,x,u) returns the discrete representation of the
% quaternion-based attitude dynamics at the point (x,u) and time t. The
% struct P must contain at least an entry called 'inertia' and one called 
% 'dt' that is the discretization step size. 
%
% T. Reynolds -- RAIN Lab.

% States
q   = x(1:4)./norm(x(1:4));
w   = x(5:7);

% Constants
dt  = P.dt;
J   = P.inertia;

% Quaternion parts
Om_w    = [ 0    -w(1) -w(2) -w(3);
            w(1)  0     w(3) -w(2);
            w(2) -w(3)  0     w(1);
            w(3)  w(2) -w(1)  0 ];
dfq_dq  = expm( 0.5*dt*Om_w );
fw      = J\( u - skew(w)*J*w );
dfw_dw  = -J\( skew(w)*J - skew(J*w) );

At  = [ dfq_dq zeros(4,3); zeros(3,4) eye(3)+dt*dfw_dw ];
Bt  = [ zeros(4,3); inv(J) ];
zt  = [ zeros(4,1); dt*( fw - dfw_dw*w ) ];

end

function S = skew(s)
    S   = [ 0     s(3) -s(2);
           -s(3)  0     s(1);
            s(2) -s(1)  0 ];
end

