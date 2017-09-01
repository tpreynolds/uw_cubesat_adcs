function [ q_star ] = Q_conj( q )

% Conjugates a quaternion according to
%   q_star  = [-q_v ; q_0]

if length(q) ~= 4
    error('Input vector is not a quaternion')
end

q = reshape(q,4,1);

q_v     = q(1:3);
q_0     = q(4);

q_star  = [ -q_v; q_0 ];

q_star  = reshape(q_star,4,1);


end

