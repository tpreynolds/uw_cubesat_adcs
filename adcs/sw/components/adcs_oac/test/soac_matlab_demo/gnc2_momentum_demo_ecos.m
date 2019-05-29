% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab
% clear variables; close all;
OAC     = struct;
opts    = ecosoptimset('verbose',0);
rng(2)

% Controller parameters
N = 10; OAC.N = N; 
Nx = 10; OAC.Nx = Nx;
Nu = 3; OAC.Nu = Nu; 
OAC.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
               -4.884e-05  0.0346     7.124e-06;
               -7.393e-05  7.124e-06  0.0075 ];
OAC.Jw      = diag([2.9382e-05,2.9382e-05,2.9382e-05]);
OAC.Om0     = 0.10471975511966 * [ 1000;1000;1000 ]; % initial wheel speeds [rad/s]
OAC.T_max   = 3.2e-3; % 1mNm
OAC.w_max   = 0.3;  % rad/s
OAC.s_min   = 15;   % s
OAC.s_max   = 20;   % s
OAC.w_v     = 1e2;  % weight
OAC.method  = 'linear';     

% Boundary Conditions
n   = [1;1;1]./norm([1;1;1]);
q0  = [ cosd(60/2); sind(60/2).*n ];
hb0 = OAC.inertia * [ 0.0; 0.0; 0.0 ];
hw0 = OAC.Jw * 0.10471975511966 * [ 1000; 1000; 1000 ]; % rad/s
xi  = [ q0; hb0; hw0 ];
qf  = [ 1.0; 0.0; 0.0; 0.0 ];
hbf = OAC.inertia * [ 0.0; 0.0; 0.0 ];
xf  = [ qf; hbf ]; % hwf unconstrained

% Constraints
xI      = [ 1.0; 0.0; 0.0 ];        % Inertial vector
yB      = [ 0.0; 0.0; -1.0 ];       % Body vector
amax    = deg2rad(60);              % min. separating angle
M       = [ xI*yB'+yB*xI'-(xI'*yB)*eye(3)   skew(xI)*yB;
            (skew(xI)*yB)'                  xI'*yB ] - cos(amax)*eye(4);
Mt      = M + 2*eye(4);     % M_tilde
ME      = sqrtm(Mt);        % Exclusion constraint matrix
smin    = 15;
smax    = 25;

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));

% Indices
OAC.id_x    = 1:OAC.N*OAC.Nx;
OAC.id_u    = OAC.id_x(end) + (1:OAC.N*OAC.Nu);
OAC.id_g    = OAC.id_u(end) + 1;
OAC.id_s    = OAC.id_g(end) + 1;
OAC.id_v    = OAC.id_s(end) + (1:OAC.N*OAC.Nx);
OAC.id_etav = OAC.id_v(end) + (1:OAC.N*OAC.Nx);

Hx  = [ eye(N*Nx) zeros(N*Nx,N*(Nu+2*Nx)+2) ];
Hw  = [ kron(eye(N),[zeros(3,4) inv(OAC.inertia) zeros(3,3)]) zeros(3*N,N*(Nu+2*Nx)+2) ];
Hu  = [ zeros(N*Nu,N*Nx) eye(N*Nu) zeros(N*Nu,2*N*Nx+2) ];
Hv  = [ zeros(N*Nx) zeros(N*Nx,N*Nu) ...
        zeros(N*Nx,1) zeros(N*Nx,1) eye(N*Nx) zeros(N*Nx) ];
Hg  = [ zeros(1,N*(Nx+Nu)) 1 0 zeros(1,2*N*Nx) ];
Hs  = [ zeros(1,N*(Nx+Nu)) 0 1 zeros(1,2*N*Nx) ];
Hev = [ zeros(N*Nx,N*(2*Nx+Nu)+2) eye(N*Nx) ];

% Initial trajectory
x0      = zeros(Nx,N);
u0      = zeros(Nu,N);
s0      = OAC.s_max;
OAC.t0  = 0;
OAC.tf  = s0; 
OAC.t   = linspace(OAC.t0,OAC.tf,OAC.N);
OAC.tau = linspace(OAC.t0,1,OAC.N);
[qb,flag] = Q_SLERP(q0,qf,OAC.t);
for k = 1:OAC.N
    x0(:,k)   = [ qb(:,k); zeros(3,1); hw0 ];
    u0(:,k)     = zeros(3,1);
end
x0 = reshape(x0,Nx*N,1);
u0 = reshape(u0,Nu*N,1);
ecos_time = 0.0;
u_max = OAC.T_max * ones(N*Nu,1);
w_max = OAC.w_max * ones(N*3,1);

% Successive Loop
for iter = 1:10

OAC.X   = x0;
OAC.U   = u0;
OAC.s   = s0;

% Discretize
[EH,BE,ES,ZE] = foh_p(OAC);

% Cost function
c   = [ zeros(1,N*(Nx+Nu)) 1 0 zeros(1,N*Nx) OAC.w_v*ones(1,N*Nx) ];
% Equality constraints
A   = sparse([ eye(Nx) repmat(zeros(Nx),1,N-1) zeros(Nx,N*Nu) zeros(Nx,2) zeros(Nx,N*Nx) zeros(Nx,N*Nx);
               EH-eye(size(EH)) BE zeros(N*Nx,1) ES eye(N*Nx) zeros(N*Nx,N*Nx);
               repmat(zeros(7,Nx),1,N-1) horzcat(eye(7),zeros(7,3)) zeros(7,N*Nu) zeros(7,2) zeros(7,2*N*Nx) ]);
b   = [xi; -ZE; xf];
% Inequality constraints
Glin    = [ Hw; -Hw; Hu; -Hu; Hs; -Hs; Hv-Hev; -Hv-Hev ];
Gquad   = [ -Hg/sqrt(2); -Hu; Hg/sqrt(2) ];
G       = sparse([ Glin; Gquad ]);
% G       = sparse(Glin);
hlin    = [ w_max; w_max; ...               % wmax sized right already
            u_max; u_max; ...               % umax sized right already
            smax; -smin; ...
            zeros(N*Nx,1); zeros(N*Nx,1) ];
hquad   = [ 1/sqrt(2); zeros(size(Hu,1),1); 1/sqrt(2) ];
h       = [ hlin; hquad ];
% h   = hlin;
% % Dimensions
dims    = struct;
dims.l  = size(Glin,1);
dims.q  = size(Hu,1)+2;

% Solve with ecos
[ze,ye,info,~,~] = ecos(c',G,h,dims,A,b,opts);
    
    % Get ECOS states
    xe   = ze(OAC.id_x);
    ue   = ze(OAC.id_u);
    se   = ze(OAC.id_s);
    ve   = ze(OAC.id_v);
    
    % Difference from last solution
    diff        = norm(xe - x0,1);
    ecos_time   = ecos_time + info.timing.runtime;
    x0 = full(xe);
    u0 = full(ue);
    s0 = se;
    
    % Display iter information
    fprintf('Iter: %d |',iter)
    fprintf(' Solver time: %2.2g s |',info.timing.runtime)
    fprintf(' HoG: %02.2e |',norm(ve,1))
    fprintf(' Diff: %02.2e |',diff)
    fprintf(' t_f: %2.2f \n',se)
    
    % Check exit condition
    if( (norm(ve,1) < 1e-5) && (diff < 1e-1) )
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
% x0 = full(xe(1:OAC.Nx));
x0 = [full(xe(1:4));full(J\xe(5:7));full(xe(8:10))];
% X = rk4(@(t,y)Q_ode_p(OAC,t,y,uopt,OAC.t),T,x0);
X = rk4(@(t,y)Q_ode(OAC,t,y,uopt,OAC.t),T,x0);

for k = 1:OAC.N
    qk          = X(k,1:4);
    E_val(k)    = qk*M*qk';
end

% Plot
close all
figure(1)
subplot(3,1,1), hold on, grid on
plot(T,X(:,1:4),'LineWidth',1)
plot(OAC.t,xopt(1:4,:),'ko','MarkerSize',3)
set(gca,'Ylim',[-1 1])
xlabel('Time [s]')
title('Attitude Quaternion')
subplot(3,1,2), hold on, grid on
% plot(T,OAC.inertia\X(:,5:7)','LineWidth',1)
% plot(OAC.t,OAC.inertia\xopt(5:7,:),'ko','MarkerSize',3)
plot(T,X(:,5:7)','LineWidth',1)
plot(OAC.t,OAC.inertia\xopt(5:7,:),'ko','MarkerSize',3)
plot([0 se],[OAC.w_max OAC.w_max],'r--','LineWidth',1)
plot([0 se],[-OAC.w_max -OAC.w_max],'r--','LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity')
subplot(3,1,3), hold on, grid on
plot(T,X(:,8:10),'LineWidth',1)
plot(OAC.t,xopt(8:10,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Wheel Momentum')

figure(2), hold on, grid on
plot(OAC.t,uopt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')

figure(3), hold on, grid on
plot(OAC.t,E_val,'LineWidth',1)
plot([0 OAC.t(end)],[2 2],'r--','LineWidth',1)
xlabel('Time [s]') 
title('Exclusion constraint')