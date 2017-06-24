function [ k_eff ] = mag_eff( length,radius,permeability )

% Magnetic Permeability
mu_r = permeability;

% Compute De-mag Factor: N_d
Nd = 4*(log(length/radius) - radius)/((length/radius)^2 - 4*log(length/radius));

% Compute Efficieny Factor: k_eff
k_eff = 1 + (mu_r - 1)/(1 + (mu_r - 1)*Nd);

end

