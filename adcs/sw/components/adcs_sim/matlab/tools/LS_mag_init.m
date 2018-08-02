% Least squares estimation of magnetic field
%
%   assumes sim_init run to set paths

% Set the orbit TLE
TLE                         = fsw_params.bus.orbit_tle;

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
f   = @(t)([ ones(3,1); cos(Om*t) * ones(3,1); sin(Om*t) * ones(3,1); ...
                cos(2*Om*t) * ones(3,1); sin(2*Om*t) * ones(3,1); ...
                cos(3*Om*t) * ones(3,1); sin(3*Om*t) * ones(3,1) ]);

% Set matrices for LS fit
n   = length(tout);         % Number of data points
m   = length(f(0));         % Number of basis functions
A   = zeros(n,m);
b   = zeros(3*n,1);

for k = 1:n
    tk                  = JD_ut1_J2000(k);
    fk                  = f(tk);
    rows                = 3*(k-1)+1:3*k;
    b(rows,1)           = mag_vec_eci_T(k,:)';
    for l = 1:(m/3)
        cols         = 3*(l-1)+1:3*l;
        A(rows,cols) = diag(fk(cols));
    end
end

X   = pinv(A) * b;

% Get vector coefficients
b0  = X(1:3);
b1  = X(4:6);
b2  = X(7:9);
b3  = X(10:12);
b4  = X(13:15);
b5  = X(16:18);
b6  = X(19:21);

F   = @(t)( b0 + b1*cos(Om*t) + b2*sin(Om*t) + ...
                b3 * cos(2*Om*t) + b4 * sin(2*Om*t) + ...
                b5 * cos(3*Om*t) + b6 * sin(3*Om*t) );
            
% Test the fit            
B_approx    = zeros(3*n,1);    
B_err       = zeros(n,1);

for k = 1:n
    tk                          = JD_ut1_J2000(k);
    B_approx(3*(k-1)+1:3*k,1)   = F(tk);
    B_true                      = mag_vec_eci_T(k,:);
    B_err(k)    = norm(B_approx(3*(k-1)+1:3*k,1) - B_true,2);
end

B_approx    = reshape(B_approx,3,n)';

% Print results
mean_err    = mean(B_err);
fprintf('The mean error is: %2.3e.\n',mean_err)

% Plot results
figure(1), hold on, grid on
plot(tout,mag_vec_eci_T,'lineWidth',1)
plot(tout,B_approx,'LineWidth',1)
xlabel('Simulation time [s]')
title('Comparison of calculated B-vectors')





