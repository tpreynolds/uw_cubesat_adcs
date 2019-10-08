% Constrained Attitude Guidance Proof of Concept
%
% T. Reynolds -- RAIN Lab
% clear variables; close all;
OAC     = struct;
opts    = ecosoptimset('verbose',0);
RPM2RADPS = 2*pi/60;
rng(2)

% Controller parameters
N = 10; OAC.N = N; 
Nx = 10; OAC.Nx = Nx;
Nu = 3; OAC.Nu = Nu; 
Nz = N*(3*Nx+Nu)+2;
OAC.inertia = [ 0.0338    -4.884e-05 -7.393e-05;
               -4.884e-05  0.0346     7.124e-06;
               -7.393e-05  7.124e-06  0.0075 ];
OAC.Jw      = diag([2.9382e-05,2.9382e-05,2.9382e-05,2.9382e-05]);
OAC.Om0     = RPM2RADPS * [ 1000;-1000;1000;-1000 ]; % initial wheel speeds [rad/s]
OAC.Aw      = [ 1 0 -1 0; 0 1 0 -1; 1 1 1 1 ];
OAC.T_max   = 3.2e-3; % 1mNm
OAC.w_max   = 0.1;  % rad/s
OAC.s_min   = 10;   % s
OAC.s_max   = 25;   % s
OAC.w_v     = 1e2;  % weight
OAC.method  = 'linear';     

% Boundary Conditions
n   = [1;1;1]./norm([1;1;1]);
q0  = [ cosd(60/2); sind(60/2).*n ];
hb0 = OAC.inertia * [ 0.0; 0.0; 0.0 ];
hw0 = OAC.Aw * OAC.Jw * OAC.Om0;
xi  = [ q0; hb0; hw0 ];
qd  = [ cosd(1/2); sind(1/2).*n ];
qf  = [1;0;0;0];%quatmultiply(qd',q0')';
hbf = OAC.inertia * [ 0.0; 0.0; 0.0 ];
xf  = [ qf; hbf ]; % hwf unconstrained

% Constraints
xI      = [ 1.0; 0.0; 0.0 ];                    % Inertial (sun) vector
yB      = [ 0.0; 0.0; -1.0 ];                   % (exclude) body vector
yyB     = [ 0.5*sqrt(2); 0.5*sqrt(2); 0.0 ];    % (include) body vector
amin    = deg2rad(60); % min. separating angle
amax    = deg2rad(90); % max. separating angle
Me = [ xI'*yB              (skew(xI)*yB)'  
       skew(xI)*yB  xI*yB'+yB*xI'-(xI'*yB)*eye(3) ] - cos(amin)*eye(4);
Mi = [ xI'*yyB              (skew(xI)*yyB)'
       skew(xI)*yyB  xI*yyB'+yyB*xI'-(xI'*yyB)*eye(3) ] - cos(amax)*eye(4);
ME      = sqrtm(Me + 2*eye(4));       % exclusion constraint matrix
MI      = sqrtm(2*eye(4) - Mi);       % inclusion constraint matrix
for i = 1:4
    for j = 1:4
        if (abs(MI(i,j))<1e-8)
            MI(i,j) = 0.0;
        end
        if (abs(ME(i,j))<1e-8)
            ME(i,j) = 0.0;
        end
    end
end
smin    = 10;               % minimum time [s]
smax    = 30;               % maximum time [s]

q_err   = quatmultiply(quatconj(q0'),qf')';
ang_err = 2*acosd(q_err(1));

% Scalings
Dq = eye(4);
Dw = OAC.w_max * eye(3);
Dh = 1e-3 * eye(3);
Dx = blkdiag(Dq,Dw,Dh);
Du = OAC.T_max * eye(3);
Ds = OAC.s_max-OAC.s_min;
Dg = 1;

% Indices
OAC.id_x    = 1:OAC.N*OAC.Nx;
OAC.id_u    = OAC.id_x(end) + (1:OAC.N*OAC.Nu);
OAC.id_g    = OAC.id_u(end) + 1;
OAC.id_s    = OAC.id_g(end) + 1;
OAC.id_v    = OAC.id_s(end) + (1:OAC.N*OAC.Nx);
OAC.id_etav = OAC.id_v(end) + (1:OAC.N*OAC.Nx);

Hq  = [ eye(4)*Dq zeros(4,6) ];
Hx  = [ kron(eye(N),eye(Nx)*Dx) zeros(N*Nx,N*(Nu+2*Nx)+2) ];
Hw  = [ kron(eye(N),[zeros(3,4) inv(OAC.inertia) zeros(3,3)]*Dx) zeros(3*N,N*(Nu+2*Nx)+2) ];
Hu  = [ zeros(N*Nu,N*Nx) kron(eye(N),eye(Nu)*Du) zeros(N*Nu,2*N*Nx+2) ];
Hv  = [ zeros(N*Nx) zeros(N*Nx,N*Nu) ...
        zeros(N*Nx,1) zeros(N*Nx,1) eye(N*Nx) zeros(N*Nx) ];
Hg  = [ zeros(1,N*(Nx+Nu)) Dg 0 zeros(1,2*N*Nx) ];
Hs  = [ zeros(1,N*(Nx+Nu)) 0 Ds zeros(1,2*N*Nx) ];
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

% cost function 
c   = [ zeros(1,N*(Nx+Nu)) Dg 0 zeros(1,N*Nx) OAC.w_v*ones(1,N*Nx) ];
% (constant) inequality constraint matrices
Glin    = [ Hw; -Hw; Hu; -Hu; Hs; -Hs; Hv-Hev; -Hv-Hev ];
Gquad   = [ -Hg/sqrt(2); -Hu; Hg/sqrt(2) ];
hlin    = [ w_max; w_max; ...               % wmax sized right already
            u_max; u_max; ...               % umax sized right already
            OAC.s_max; -OAC.s_min; ...
            zeros(N*Nx,1); zeros(N*Nx,1) ];
hquad   = [ 1/sqrt(2); zeros(size(Hu,1),1); 1/sqrt(2) ];
% constraint dimensions
dims    = struct;
dims.l  = size(Glin,1);
dims.q(1)  = size(Hu,1)+2;
% add inclusion
for k = 1:N
    Hk = zeros(Nx,Nz);
    Hk(1:Nx,Nx*(k-1)+(1:Nx)) = eye(Nx);
    Pk = MI*Hq*Dx*Hk; 
    Gk = [ zeros(1,Nz); -Pk; zeros(1,Nz) ];
    hk = [ 3/sqrt(2); zeros(size(Pk,1),1); -1/sqrt(2) ];
    Gquad = [Gquad;Gk];
    hquad = [hquad;hk];
    dims.q(k+1) = size(Pk,1)+2;
end
% add exclusion
for k = 1:N
    Hk = zeros(Nx,Nz);
    Hk(1:Nx,Nx*(k-1)+(1:Nx)) = eye(Nx);
    Pk = ME*Hq*Dx*Hk; 
    Gk = [ zeros(1,Nz); -Pk; zeros(1,Nz) ];
    hk = [ 3/sqrt(2); zeros(size(Pk,1),1); -1/sqrt(2) ];
    Gquad = [Gquad;Gk];
    hquad = [hquad;hk];
    dims.q(N+1+k) = size(Pk,1)+2;
end
G   = sparse([ Glin; Gquad ]);
h   = [ hlin; hquad ];

% Successive Loop
for iter = 1:10
    
    OAC.X   = x0;
    OAC.U   = u0;
    OAC.s   = s0;
    
    % Discretize
    [EH,BE,ES,ZE] = foh_p(OAC);
    
    for k = 1:N-1
        Ak = EH(Nx*k+(1:Nx),Nx*(k-1)+(1:Nx));
        Bkm = BE(Nx*k+(1:Nx),Nu*(k-1)+(1:Nu));
        Bkp = BE(Nx*k+(1:Nx),Nu*k+(1:Nu));
        Sk = ES(Nx*k+(1:Nx),1);
        Rk = ZE(Nx*k+(1:Nx),1);
        EH(Nx*k+(1:Nx),Nx*(k-1)+(1:Nx)) = Dx\Ak*Dx;
        BE(Nx*k+(1:Nx),Nu*(k-1)+(1:Nu)) = Dx\Bkm*Du;
        BE(Nx*k+(1:Nx),Nu*k+(1:Nu)) = Dx\Bkp*Du;
        ES(Nx*k+(1:Nx),1) = Dx\Sk*Ds;
        ZE(Nx*k+(1:Nx),1) = Dx\Rk;
    end
    
    % update equality constraints
    A   = sparse([ Dx repmat(zeros(Nx),1,N-1) zeros(Nx,N*Nu) zeros(Nx,2) zeros(Nx,N*Nx) zeros(Nx,N*Nx);
            EH-eye(size(EH)) BE zeros(N*Nx,1) ES kron(eye(N),inv(Dx)) zeros(N*Nx,N*Nx);
            repmat(zeros(7,Nx),1,N-1) horzcat(blkdiag(Dq,Dw),zeros(7,3)) zeros(7,N*Nu) zeros(7,2) zeros(7,2*N*Nx) ]);
    b   = [xi; -ZE; xf];
    
    % Solve with ecos
    [ze,ye,info,~,~] = ecos(c',G,h,dims,A,b,opts);
    
    % Get ECOS states
    xe   = kron(eye(N),Dx)*ze(OAC.id_x);
    ue   = kron(eye(N),Du)*ze(OAC.id_u);
    se   = Ds*ze(OAC.id_s);
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
    if( (norm(ve,1) < 1e-5) && (diff < 1e-2) )
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
uopt4 = zeros(4,OAC.N);
for k = 1:OAC.N
   uopt4(:,k) = pinv(OAC.Aw) * uopt(:,k); 
end
% x0 = full(xe(1:OAC.Nx));
x0 = [full(xe(1:4));full(OAC.inertia\xe(5:7));OAC.Jw*OAC.Om0];
% using this integrator is proof that the allocation scheme can be used
X = rk4(@(t,y)Q_ode_4p(OAC,t,y,uopt4,OAC.t),T,x0);
% X = rk4(@(t,y)Q_ode(OAC,t,y,uopt,OAC.t),T,x0);

E_val = zeros(size(X,1),1);
for k = 1:size(X,1)
    qk          = X(k,1:4);
    E_val(k)    = qk*Me*qk';
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
plot(T,OAC.inertia\X(:,5:7)','LineWidth',1)
plot(OAC.t,OAC.inertia\xopt(5:7,:),'ko','MarkerSize',3)
plot([0 se],[OAC.w_max OAC.w_max],'r--','LineWidth',1)
plot([0 se],[-OAC.w_max -OAC.w_max],'r--','LineWidth',1)
xlabel('Time [s]')
title('Angular Velocity')
subplot(3,1,3), hold on, grid on
plot(T,OAC.Aw*X(:,8:11)','LineWidth',1)
plot(OAC.t,xopt(8:10,:),'ko','MarkerSize',3)
xlabel('Time [s]')
title('Wheel Momentum')

figure(2), hold on, grid on
plot(OAC.t,uopt,'LineWidth',1)
xlabel('Time [s]')
title('Control Signal')

figure(3), hold on, grid on
plot(T,E_val,'LineWidth',1)
plot([0 T(end)],[2 2],'r--','LineWidth',1)
xlabel('Time [s]') 
title('Exclusion constraint')