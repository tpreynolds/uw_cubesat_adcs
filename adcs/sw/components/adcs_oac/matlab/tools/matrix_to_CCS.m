function [ Mir,Mjc,Mpr ] = matrix_to_CCS( M )

[Mir,~,Mpr] = find(M);
Mir = Mir - 1; % CCS uses zero-based row indexing
Mjc = zeros(size(M,2)+1,1);
for col = 2:size(M,2)
    Mjc(col) = Mjc(col-1)+nnz(M(:,col-1));
end
Mjc(end) = length(find(M~=0));

end

