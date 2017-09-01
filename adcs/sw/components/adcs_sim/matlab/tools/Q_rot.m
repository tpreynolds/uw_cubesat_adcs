function [ vec_rot ] = Q_rot( q,vec )

if length(q) ~= 4 || length(vec) ~= 3
    if length(q) == 3 
        q   = reshape(q,3,1);
        q   = [q; 0];
    else
        error('Input is not a quaternion or ')
    end
end

q   = reshape(q,4,1);
q   = q/norm(q);
vec   = reshape(vec,3,1);

DCM     = my_quat2dcm( q );

vec_rot     = DCM*vec;
        
end

