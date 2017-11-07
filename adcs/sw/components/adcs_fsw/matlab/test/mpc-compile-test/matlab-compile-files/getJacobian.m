function A = getJacobian( x )
% UW HuskySat-1, ADCS Subsystem
%   Updated: T. Reynolds 9.13.17

% Returns a 7x7 Jacobian matrix based on the Quaternion kinematics and
% dynamics, linearized about a given attitude and zero angular velocity.

q = x(1:4);

XIq     = [ q(1) -q(2) -q(3);
            q(2)  q(1) -q(4);
            q(3)  q(4)  q(1);
            q(4) -q(2)  q(2) ];

A = [ zeros(4) 0.5*XIq;
        zeros(3,4) zeros(3) ];

end


