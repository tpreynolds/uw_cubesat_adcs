function A = quatToMatrix(q)
%#codegen

eta = q(1);
eps = q(2:4);

A = (2*eta^2 -1)*eye(3) + 2*(eps*eps') - 2*eta*skew(eps);


end