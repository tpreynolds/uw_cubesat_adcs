function [ q ] = Q_rand( varargin )
%Q_RAND
%
% q = Q_rand() computes a random unit quaternion.
%
% q = Q_rand(rng) sets the seed of the random number generator to rng and
% then returns a random unit quaternion. 
%
% T. Reynolds -- RAIN Lab

if( nargin > 0 )
    rng(varargin{1});
end

q   = randn(4,1);
q   = q./norm(q);

end

