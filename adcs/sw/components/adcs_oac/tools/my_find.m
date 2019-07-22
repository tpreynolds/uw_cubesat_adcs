function [Mir,Mpr] = my_find(M,Mir_size)
%#codegen
[n,m] = size(M);
Mir   = zeros(Mir_size,1);
Mpr   = zeros(Mir_size,1);
M_nnz = nnz(M);

id = 1;
for col = 1:m
    for row = 1:n
        if ((M(row,col)~=0) && (id<M_nnz+1))
            Mir(id) = row-1;
            Mpr(id) = M(row,col);
            id = id + 1;
        end
    end
end

end