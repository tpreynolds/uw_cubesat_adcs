function lin = init_mpc_linearization()

lin.bus_ic.A = zeros(7,7);
lin.bus_ic.B = zeros(7,3);
lin.bus_ic.C = zeros(7,7);
lin.bus_ic.D = zeros(7,3);
lin.bus_ic.U = zeros(3,1);
lin.bus_ic.X = zeros(7,1);
lin.bus_ic.Y = zeros(7,1);
lin.bus_ic.DX = zeros(7,1);