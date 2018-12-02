% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab
clear variables; close all;
OAC     = struct;
opts    = ecosoptimset('verbose',0);

% Boundary Conditions
q0  = [ cosd(60/2); sind(60/2); 0; 0 ];
w0  = [ 0.0; 0.0; 0.0 ];
xi  = [ q0; w0 ];
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
wf  = [ 0.0; 0.0; 0.0 ];
xf  = [ qf; wf ];

% Constraints
xI      = [ 1.0; 0.0; 0.0 ];        % Inertial vector
yB      = [ 0.0; 0.0; -1.0 ];       % Body vector
amax    = deg2rad(60);              % min. separating angle
M       = [ xI*yB'+yB*xI'-(xI'*yB)*eye(3)   skew(xI)*yB;
            (skew(xI)*yB)'                  xI'*yB ] - cos(amax)*eye(4);
Mt      = M + 2*eye(4);     % M_tilde
ME      = sqrtm(Mt);        % Exclusion constraint matrix
smin    = 1;
smax    = 5;

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));
OAC.N   = ceil(ang_err/7.5);

% Controller parameters
OAC.Nx      = 7;
OAC.Nu      = 3;
OAC.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
               -4.884e-05  0.0346     7.124e-06;
               -7.393e-05  7.124e-06  0.0075 ];
OAC.T_max   = 1e-2;
OAC.method  = 'linear';     % discretization method
% Indices
OAC.id_x    = 1:OAC.N*OAC.Nx;
OAC.id_u    = OAC.id_x(end) + (1:OAC.N*OAC.Nu);
OAC.id_s    = OAC.id_u(end) + 1;
OAC.id_v    = OAC.id_s(end) + (1:OAC.N*OAC.Nx);
OAC.id_etas = OAC.id_v(end) + (1:OAC.N);
Hx  = [ eye(OAC.N*OAC.Nx) zeros(OAC.N*OAC.Nx,OAC.N*(OAC.Nu+2*OAC.Nx)+2) ];
Hu  = [ zeros(OAC.N*OAC.Nu,OAC.N*OAC.Nx) eye(OAC.N*OAC.Nu) zeros(OAC.N*OAC.Nu,2*OAC.N*OAC.Nx+2) ];
Hv  = [ zeros(OAC.N*OAC.Nx) zeros(OAC.N*OAC.Nx,OAC.N*OAC.Nu) ...
        zeros(OAC.N*OAC.Nx,1) eye(OAC.N*OAC.Nx) zeros(OAC.N*OAC.Nx,OAC.N*OAC.Nx+1) ];
Hs  = [ zeros(1,OAC.N*(OAC.Nx+OAC.Nu)) 1 zeros(1,2*OAC.N*OAC.Nx+1) ];
Hes = [ zeros(1,OAC.N*(OAC.Nx+OAC.Nu)) 0 zeros(1,OAC.N*OAC.Nx) 1 zeros(1,OAC.N*OAC.Nx) ];
Hev = [ zeros(OAC.N*OAC.Nx,OAC.N*(2*OAC.Nx+OAC.Nu)+2) eye(OAC.N*OAC.Nx) ];
W   = sqrt(Hs'*Hs);

% Initial trajectory
x0      = zeros(7,OAC.N);
u0      = zeros(3,OAC.N);
s0      = 2*sqrt((pi/180)*ang_err);
OAC.t0  = 0;
OAC.tf  = s0; 
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
OAC.tau = linspace(OAC.t0,1,OAC.N);
[qb,flag] = Q_SLERP(q0,qf,OAC.t);
for k = 1:OAC.N-1
    x0(:,k)   = [ qb(:,k); zeros(3,1) ];
    u0(:,k)     = zeros(3,1);
end
x0 = reshape(x0,OAC.Nx*OAC.N,1);
u0 = reshape(u0,OAC.Nu*OAC.N,1);
ecos_time = 0.0;
u_max = OAC.T_max * ones(OAC.N*OAC.Nu,1);

% Successive Loop
for iter = 1:10

OAC.X   = x0;
OAC.U   = u0;
OAC.s   = s0;
% Discretize
if( strcmp(OAC.method,'linear') )
    [EH,BE,ES,ZE] = foh(OAC);
else
    [EH,BE,ES,ZE] = zoh(OAC);
end

% % Cost function
c   = [ zeros(1,OAC.N*(OAC.Nx+OAC.Nu)) 1 zeros(1,OAC.N*OAC.Nx) 1e-1*1 1e2*ones(1,OAC.N*OAC.Nx) ];
% % Equality constraints
A   = sparse([ eye(OAC.Nx) repmat(zeros(OAC.Nx),1,OAC.N-1) zeros(OAC.Nx,OAC.N*OAC.Nu) zeros(OAC.Nx,1) zeros(OAC.Nx,OAC.N*OAC.Nx) zeros(OAC.Nx,1) zeros(OAC.Nx,OAC.N*OAC.Nx);
        EH-eye(size(EH)) BE ES eye(OAC.Nx*OAC.N) zeros(OAC.N*OAC.Nx,OAC.N*OAC.Nx+1);
        repmat(zeros(OAC.Nx),1,OAC.N-1) eye(OAC.Nx) zeros(OAC.Nx,OAC.N*OAC.Nu) zeros(OAC.Nx,1) zeros(OAC.Nx,OAC.N*OAC.Nx) zeros(OAC.Nx,1) zeros(OAC.Nx,OAC.N*OAC.Nx) ]);
b   = [xi; -ZE; xf];
% % Inequality constraints
Glin    = [ Hs; -Hs; Hu; -Hu; Hv-Hev; -Hv-Hev ];
% Gquad   = [ -(2*s0*Hs+Hes); -W; (2*s0*Hs+Hes) ];
% G       = sparse([ Glin; Gquad ]);
hlin    = [ 4*sqrt((pi/180)*ang_err); -0.5*sqrt((pi/180)*ang_err); u_max; u_max; zeros(OAC.N*OAC.Nx,1); zeros(OAC.N*OAC.Nx,1) ];
% hquad   = [ 0.5; zeros(size(W,1),1); 0.5 ];
% h       = [ hlin; hquad ];
% % Dimensions
% dims    = struct;
% dims.l  = size(Glin,1);
% dims.q  = size(W,1)+2;
% 
% % Solve with ecos
% [ze,ye,info,~,~] = ecos(c',G,h,dims,A,b,opts);

cvx_clear
cvx_tic;
cvx_begin quiet
    cvx_solver('ecos')
    cvx_precision('low')
    
    % Variables
    variable ze(OAC.N*(3*OAC.Nx+OAC.Nu)+2)
    
    % Cost function
    minimize( dot(c,ze) )
    
    subject to
        
    % Second order cones
    norm([ 0.5*(1+s0^2-dot(2*s0*Hs+Hes,ze)); dot(Hs,ze) ]) <= 0.5*(1-s0^2+dot(2*s0*Hs+Hes,ze)); % time trust region
    % Linear cones
    Glin*ze <= hlin;
   
    % Dynamics
    b == A * ze;
    
    % Quadratic constraints
    for k = 1:OAC.N
        qk  = ze(OAC.Nx*(k-1)+1:OAC.Nx*(k-1)+4);
        norm( ME*qk ) <= 2;
    end
        
    cvx_end
    sol_time = cvx_toc;
    
    % Compute ECOS states
    xe   = ze(1:OAC.N*OAC.Nx);
    ue   = ze(OAC.N*OAC.Nx+1:OAC.N*(OAC.Nx+OAC.Nu));
    se   = ze(OAC.N*(OAC.Nx+OAC.Nu)+1);
    ve   = ze(OAC.N*(OAC.Nx+OAC.Nu)+2:OAC.N*(2*OAC.Nx+OAC.Nu)+1);
    
    % Difference from last solution
%     x   = z(1:OAC.N*OAC.Nx);
%     u   = z(OAC.N*OAC.Nx+1:OAC.N*(OAC.Nx+OAC.Nu));
%     s   = z(OAC.N*(OAC.Nx+OAC.Nu)+1);
%     v   = z(OAC.N*(OAC.Nx+OAC.Nu)+2:OAC.N*(2*OAC.Nx+OAC.Nu)+1);
    diff        = norm(xe - x0,1);
%     ecos_time   = ecos_time + info.timing.runtime;
    x0 = full(xe);
    u0 = full(ue);
    s0 = se;
    
    % Display iter information
    fprintf('Iter: %d |',iter)
%     fprintf(' Solver time: %2.2g s |',info.timing.runtime)
    fprintf(' HoG: %02.2e |',norm(ve,1))
    fprintf(' Diff: %02.2e |',diff)
    fprintf(' t_f: %2.2f \n',se)
%     fprintf(' Solver Time: %2.2g s |',sol_time(5))
%     fprintf(' HoG: %02.2e |',norm(v,1))
%     fprintf(' Diff: %02.2e |',diff)
%     fprintf(' t_f: %2.2f \n',s)
%     fprintf(' ECOS differences: |')
%     fprintf(' x: %2.2e',norm(x-xe))
%     fprintf(' u: %2.2e',norm(u-ue))
%     fprintf(' s: %2.2e',norm(s-se))
%     fprintf(' v: %2.2e',norm(v-ve))
%     fprintf(' Solver Time: %2.2g s \n',info.timing.runtime)
    
    % Check exit condition
    if( (norm(ve,1) < 1e-5) && (diff < 1e-5) )
        fprintf('Converged.\n\n')
        break;
    end
end

% Print solution time
fprintf('Total Solver time: %g s\n',ecos_time)

% Integrate through ODE
T = linspace(0,se,100);
OAC.tf  = se;
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
xopt    = reshape(full(xe),OAC.Nx,OAC.N);
uopt    = reshape(full(ue),OAC.Nu,OAC.N);
if( strcmp(OAC.method,'previous') )
   uopt = [ uopt(:,2:end) uopt(:,end) ]; 
end
X = rk4(@(t,y)Q_ode(OAC,t,y,uopt,OAC.t),T,full(xe(1:OAC.Nx)));

for k = 1:OAC.N
    qk          = X(k,1:4);
    E_val(k)    = qk*M*qk';
end

% Plot
close all
figure(1)
subplot(2,1,1), hold on, grid on
plot(T,X(:,1:4),'LineWidth',1)
plot(OAC.t,xopt(1:4,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(2,1,2), hold on, grid on
plot(T,X(:,5:7),'LineWidth',1)
plot(OAC.t,xopt(5:7,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Angular Velocity')

figure(2), hold on, grid on
if( strcmp(OAC.method,'linear') )
    plot(OAC.t,uopt,'LineWidth',1)
else
    stairs(OAC.t,uopt','LineWidth',1)
end
xlabel('Time [s]')
title('Control Signal')

figure(3), hold on, grid on
plot(OAC.t,E_val,'LineWidth',1)
plot([0 OAC.t(end)],[2 2],'r--','LineWidth',1)
xlabel('Time [s]') 
title('Exclusion constraint')


