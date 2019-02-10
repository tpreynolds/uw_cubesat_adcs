% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab

clear variables; close all;
OAC     = struct;
opts    = ecosoptimset('verbose',0);

rng(10)
A   = diag(rand(4,1));
b   = randn(4,1);
c   = randn(1,1);
f   = randn(4,1);

cvx_begin quiet
    cvx_solver('ecos')
    variable x1(4)
    minimize( f'*x1 )
    subject to
    
    0.5*x1'*(A'*A)*x1 + b'*x1 + c <= 0;
    
cvx_end

% Inequality constraints
bhalf = b./sqrt(2);
zerocol = zeros(size(A,1),1);
G = sparse([ bhalf';
             -A;
             -bhalf']);
h = [ (1/sqrt(2))*(1-c); zerocol; (1/sqrt(2))*(1+c) ];

% Dimensions
dims    = struct;
dims.l  = 0;
dims.q  = size(A,1)+2;
% Solve with ecos
[xe,de,info,~,~] = ecos(f,G,h,dims,opts);

cvx_begin quiet
    cvx_solver('ecos')
    variable x2(4)
    minimize( f'*x2 )
    subject to
    
    norm([ A*x2; (1/sqrt(2))*(1 + b'*x2 + c) ]) <= (1/sqrt(2))*( 1 - b'*x2 - c);
    
cvx_end
        
err1     = norm(x1-x2);
err2     = norm(xe-x1);
err3     = norm(xe-x2);
fprintf('Error are: %0.5e    %0.5e    %0.5e\n',err1,err2,err3)


