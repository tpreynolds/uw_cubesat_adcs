function [x] = rk4(fun,t,x_i)

N = length(t);
n = length(x_i);
x = zeros(N,n);

x(1,:) = x_i';

for k=1:N-1
  tk = t(k);
  xk = x(k,:)';
  tkp1 = t(k+1);
  h = tkp1-tk;

  k1 = feval(fun,tk,xk);
  k2 = feval(fun,tk+h/2,xk+h/2*k1);
  k3 = feval(fun,tk+h/2,xk+h/2*k2);
  k4 = feval(fun,tk+h,xk+h*k3);

  x(k+1,:) = (xk+h/6*(k1+2*k2+2*k3+k4))';
end
