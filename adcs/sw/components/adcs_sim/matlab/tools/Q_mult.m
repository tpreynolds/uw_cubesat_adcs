function [ qxp ] = Q_mult( q,p )

if length(q) ~= 4 || length(p) ~= 4
    if length(q) == 3 && length(p) == 3
        q   = reshape(q,3,1);
        q   = [q; 0];
        p   = reshape(p,3,1);
        p   = [p; 0];
    else
        error('Input is not a quaternion')
    end
end

q   = reshape(q,4,1);
p   = reshape(p,4,1);

qv  = q(1:3);
q0  = q(4);

qv_skew     = skew(qv);

q_skew  = [ qv_skew + q0*eye(3)     qv;
            -qv'                    q0 ];

qxp     = q_skew*p;        
        
end

