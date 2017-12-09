function [ X ] = skew( x )
% UW HuskySat-1, ADCS Subsystem
% Last Update: E. Hansen 12.8.2017

%Transforms a vector into a skew symmetric matrix (Levi-Civita)
%--------------------------------------------------------------------------

X = [0 -x(3) x(2);x(3) 0 -x(1);-x(2) x(1) 0];

end

