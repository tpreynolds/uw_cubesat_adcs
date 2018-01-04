function q = attitudeToQuat(A)
%#codegen
% converts the proper orthogonal matrix A into a (scalar-first) quaternion

qw = 0.5*sqrt(1 + A(1,1) + A(2,2) + A(3,3));
qx = (A(3,2) - A(2,3))/( 4 *qw);
qy = (A(1,3) - A(3,1))/( 4 *qw);
qz = (A(2,1) - A(1,2))/( 4 *qw);

q = [qw qx qy qz]';



end
