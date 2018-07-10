%%
load("images.mat", "im_array")

%helper function: reshape()
%%
oneToEighty = indices;

% set A = training_imgs
A = im_array(oneToEighty(1:60),:);
% set B = test_imgs
B = im_array(oneToEighty(61:80),:);

% First Method to get eigen vectors
A_T = A.';
AA_T = double(A) * double(A_T);
[V, D] = eig(AA_T);
% V2 is eigenfaces of A_T*A
V2 = double(A_T) * double(V);

SixtyEigVals = zeros(1,60);
for i = 1:60
    SixtyEigVals(i) = D(i,i);
end
[~, SixtyEigValsDescIdx] = sort(SixtyEigVals, 'descend');
FourtyEigenVectorsDesc = V2(:,SixtyEigValsDescIdx(1:40));

normVec = normc(FourtyEigenVectorsDesc);

EigenFaces = cell(5,8);
% 
% FirstEigen = reshape(V2(:,1),[128,128]);
% 
% NormFirstEigen = FirstEigen;
% 
% imshow(FirstEigen,[min(min(FirstEigen)),max(max(FirstEigen))]);


%%
c = 1;
for i = 1:5
    for j = 1:8
       EigenFaces{i,j} = reshape(V2(:,c),[128,128]);
       c = c + 1;
    end
end

figure;
k=1;
for i=1:5
    for j=1:8
        subplot(5,8,k)
        imshow(EigenFaces{i,j},[min(min(EigenFaces{i,j})),max(max(EigenFaces{i,j}))]);
        k=k+1;
    end
end




% Second Method to get eigen vectors
% [U,S,V] = svd(double(A), "econ");
% V_T = V.';
% %Select the first 40 eigenvals from 60 or from 40? I used 60
% SixtyEigVals = zeros(1,60);
% for i = 1:60
%     SixtyEigVals(i) = S(i,i);
% end
% [~, SixtyEigValsDescIdx] = sort(SixtyEigVals, 'descend');
% FourtyEigenVectorsDesc = V_T(SixtyEigValsDescIdx(1:40),:);
% normVec = normr(FourtyEigenVectorsDesc);








