function [ q_inv ] = Q_inv( q )

if length(q) ~= 4 
    if length(q) == 3 
        q   = reshape(q,3,1);
        q   = [q; 0];
    else
        error('Input is not a quaternion or ')
    end
end

q   = reshape(q,4,1);
q   = q/norm(q);

q_inv   = Q_mult(q,Q_conj(q));

q_inv   = reshape(q_inv,4,1);


end

