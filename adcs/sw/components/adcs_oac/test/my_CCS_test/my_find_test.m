load('gtest.mat')

X        = Gfull;
Xir_size = 674;
Xpr_size = 674;

tic;
[Xir,Xpr] = my_find(X,Xir_size);
Xjc = zeros(size(X,2)+1,1);
for col = 2:size(X,2)
    Xjc(col) = Xjc(col-1)+nnz(X(:,col-1));
end
Xjc(end) = nnz(X);
ttt = toc;

[Xir_true,Xjc_true,Xpr_true] = matrix_to_CCS(X);
Xir_true = [Xir_true; zeros(Xir_size-numel(Xir_true),1) ];
Xpr_true = [Xpr_true; zeros(Xpr_size-numel(Xpr_true),1) ];

test_ir = Xir - Xir_true;
test_pr = Xpr - Xpr_true;
test_jc = Xjc - Xjc_true;
if (nnz(test_ir)==0 && nnz(test_pr)==0 && nnz(test_jc)==0)
    fprintf('Yup. Time: %0.3f\n',ttt)
else
    fprintf('Nope.\n')
end