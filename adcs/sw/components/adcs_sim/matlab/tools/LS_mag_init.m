% Least squares estimation of magnetic field
%
%   assumes sim_init run to set paths

% Set the orbit TLE
TLE                         = fsw_params.bus.orbit_tle;
% TLE(2)  = TLE(2) - fsw_params.constants.time.JD_J2000;

% Compute orbital frequency
Om  = TLE(9) * fsw_params.constants.convert.revpday_2_radpmin * ...
                fsw_params.constants.convert.rad2rev * ...
                fsw_params.constants.convert.RPM_2_radps;
            
% Set run time to at least two orbits
run_time                    = 10800;

% Set the test sample time to 1s
sim_params.sample_time_s    = 1;

% Load model, set params and simulate
mdl         = 'LS_mag';
load_system(mdl);
set_param(mdl,'StopTime', num2str(run_time));
sim(mdl);

% Basis functions
f   = @(t)([ 1; cos(Om*t); sin(Om*t); ...
                cos(2*Om*t); sin(2*Om*t); ...
                cos(3*Om*t); sin(3*Om*t) ]);

% Set matrices for LS fit
n   = length(tout);         % Number of data points
m   = length(f(0));         % Number of basis functions
A   = zeros(n,m);
bx  = zeros(n,1);
by  = zeros(n,1);
bz  = zeros(n,1);

% Solve for coefficients
for row = 1:n
   tk   = fsw_params.constants.time.day2sec * (JD_ut1_J2000(row) - TLE(2));
   fk   = f(tk);
   bx(row,1) = mag_vec_eci_T(row,1);
   by(row,1) = mag_vec_eci_T(row,2);
   bz(row,1) = mag_vec_eci_T(row,3);
   for col = 1:m
      A(row,col) = fk(col); 
   end
end

Xx  = pinv(A) * bx;
Xy  = pinv(A) * by;
Xz  = pinv(A) * bz;

X   = [ Xx'; Xy'; Xz' ];

% Get vector coefficients
b0  = X(:,1);
b1  = X(:,2);
b2  = X(:,3);
b3  = X(:,4);
b4  = X(:,5);
b5  = X(:,6);
b6  = X(:,7);

F   = @(t)( b0 + b1*cos(Om*t) + b2*sin(Om*t) + ...
                b3 * cos(2*Om*t) + b4 * sin(2*Om*t) + ...
                b5 * cos(3*Om*t) + b6 * sin(3*Om*t) );
            
% Test the fit            
B_approx    = zeros(3*n,1);    
B_err       = zeros(n,1);

for k = 1:n
    tk                          = fsw_params.constants.time.day2sec * (JD_ut1_J2000(k) - TLE(2));
    B_approx(3*(k-1)+1:3*k,1)   = F(tk);
    B_true                      = mag_vec_eci_T(k,:);
    B_err(k)    = norm(B_approx(3*(k-1)+1:3*k,1) - B_true,2);
end

B_approx    = reshape(B_approx,3,n)';

% Print results
mean_err    = mean(B_err);
fprintf('The mean error is: %2.3e.\n',mean_err)

% Plot results
close all
figure(1), hold on, grid on
plot(tout,mag_vec_eci_T,'lineWidth',1)
plot(tout,B_approx,'--','LineWidth',1)
xlabel('Simulation time [s]','FontSize',14)
ylabel('B [T]','FontSize',14)
title('WMM 2015 versus LS Magnetic Field','FontSize',16)

% Save coefficients
save('../../adcs_fsw/matlab/tools/mag_field_approx.mat','X')



