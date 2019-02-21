function [Mir,Mpr] = my_find(M,Mir_size,Mpr_size)
%#codegen
    Mir = zeros(Mir_size,1);
    Mpr = zeros(Mpr_size,1);
    [n,m] = size(M);
    k = 1;
    for j = 1:m
        for i = 1:n
            if (M(i,j) ~= 0)
                Mir(k) = i;
                Mpr(k) = M(i,j);
                k = k+1;
            end
        end
    end
end

