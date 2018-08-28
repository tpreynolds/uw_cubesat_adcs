function [qt,FLAG] = Q_SLERP( q0,q1,tspan )
%Q_SLERP 
%
% Q_SLERP(q0,q1,tspan) Uses Spherical Linear intERPolation to 
% interpolate between two quaternions given the time space tspan. 
% Both q0 and q1 must be quaternions.
%
% T.Reynolds -- RAIN Lab.
%#codegen

FLAG = int8(0);

if( length(q0)~=4 || length(q1)~=4 )
   FLAG = int8(-1);
   qt   = repmat([1.0;0.0;0.0;0.0],4,length(tspan));
   return;
end

% Reshape inputs to be column vectors
q0  = reshape(q0, 4, 1);
q1  = reshape(q1, 4 ,1);
len = length(tspan);

% Change tspan to make sure it is [ 0 , 1 ]
if( tspan(1) ~= 0 )
    tspan   = tspan - tspan(1);
end

if( tspan(end) ~= 1 )
    tspan   = tspan./tspan(end);
end

% Find angle between inputs
ang = acos(dot(q0,q1));
if( ang > pi )
    FLAG = int8(-1);
    qt   = repmat([1.0;0.0;0.0;0.0],4,length(tspan));
    return;
end

sang    = sin(ang);
qt      = zeros(4,len);
for k = 1:len
    t       = tspan(k);
    qt(:,k) = (sin((1 - t)*ang)/sang)*q0 + (sin(t*ang)/sang)*q1;
end

end

