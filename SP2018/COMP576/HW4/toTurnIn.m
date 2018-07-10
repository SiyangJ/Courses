index1 = 1;
index2 = 2;
index3 = 3;
index4 = 4;

dim = 128;

[n,d] = size(im_array);

ntrain = floor(3/4*n);
ntest = n-ntrain;

%indices = randperm(n);
indices = 1:n;
trainIndex = indices(1:ntrain);
trainImArr = im_array(trainIndex,:);

[Utr,Str] = eig(trainImArr*trainImArr');
Str = diag(Str);
[~,piv] = sort(Str,'descend');

Vtr = trainImArr'*Utr;

Vtr = Vtr(:,piv);
Vtr = normc(Vtr);

turnIndices = [index1,index2,index3,index4];

recons = (trainImArr(turnIndices,:)*Vtr(:,1:40))*Vtr(:,1:40)';

face1 = recons(1,:);
face2 = recons(2,:);
face3 = recons(3,:);
face4 = recons(4,:);

rmse1 = rms(mat2gray(trainImArr(index1,:)-face1));
rmse2 = rms(mat2gray(trainImArr(index2,:)-face2));
rmse3 = rms(mat2gray(trainImArr(index3,:)-face3));
rmse4 = rms(mat2gray(trainImArr(index4,:)-face4));

%%
index1 = 45;
index2 = 26;

dim = 128;

[n,d] = size(im_array);

ntrain = floor(3/4*n);
ntest = n-ntrain;

%indices = randperm(n);
indices = 1:n;
trainIndex = indices(1:ntrain);
trainImArr = im_array(trainIndex,:);

[Utr,Str] = eig(trainImArr*trainImArr');
Str = diag(Str);
[~,piv] = sort(Str,'descend');

Vtr = trainImArr'*Utr;

Vtr = Vtr(:,piv);
Vtr = normc(Vtr);

turnIndices = [index1,index2];

coeffs = im_array(turnIndices,:)*Vtr(:,1:40);
recons = coeffs*Vtr(:,1:40)';
face0 = recons(1,:);
face1 = recons(2,:);

morphed_face = (coeffs(1,:)+0.25*(coeffs(2,:)-coeffs(1,:)))*Vtr(:,1:40)';

figure
subplot(2,2,1)
imshow(mat2gray(reshape(face0,[128,128])))
subplot(2,2,2)
imshow(mat2gray(reshape(face1,[128,128])))
subplot(2,2,3)
imshow(mat2gray(reshape(morphed_face,[128,128])))

%%

index1 = 65;
index2 = 62;
index3 = 64;
index4 = 68;

    dim = 128;

[n,d] = size(im_array);

ntrain = floor(3/4*n);
ntest = n-ntrain;

%indices = randperm(n);
indices = 1:n;
trainIndex = indices(1:ntrain);
trainImArr = im_array(trainIndex,:);

[Utr,Str,Vtr] = svd(trainImArr,'econ');

turnIndices = [index1,index2,index3,index4];

recons = (im_array(turnIndices,:)*Vtr(:,1:40))*Vtr(:,1:40)';

face1 = recons(1,:);
face2 = recons(2,:);
face3 = recons(3,:);
face4 = recons(4,:);

% rmse1 = rms(mat2gray(im_array(index1,:)-face1))
% rmse2 = rms(mat2gray(im_array(index2,:)-face2))
% rmse3 = rms(mat2gray(im_array(index3,:)-face3))
% rmse4 = rms(mat2gray(im_array(index4,:)-face4))

rmse1 = rms(mat2gray(im_array(index1,:))-mat2gray(face1));
rmse2 = rms(mat2gray(im_array(index2,:))-mat2gray(face2));
rmse3 = rms(mat2gray(im_array(index3,:))-mat2gray(face3));
rmse4 = rms(mat2gray(im_array(index4,:))-mat2gray(face4));


%%
n=500;
k = n/30;
    dim = n;
    ky = 0;
kx = k/dim;
kx2 = kx+1;

% im1 = zeros(dim);
% im2 = zeros(dim);
% 
% for i=1:dim
%     for j=1:dim
%         im1(i,j) = sin((ky*i+kx*j)*2*pi);
%         im2(i,j) = sin((ky*i+kx2*j)*2*pi);
%     end
% end


[X,Y] = meshgrid(1:dim,1:dim);
im1 = sin(kx*2*pi*X);
im2 = sin(kx2*2*pi*X);

dimr = 4;
fac = dim/dimr;

im1_sampled = zeros(fac);
im2_sampled = zeros(fac);

for i=1:fac
    for j=1:fac
        im1_sampled(i,j) = mean(mean(im1((dimr*(i-1)+1):dimr*i,(dimr*(j-1)+1):dimr*j)));
        im2_sampled(i,j) = mean(mean(im2((dimr*(i-1)+1):dimr*i,(dimr*(j-1)+1):dimr*j)));
    end
end

figure
subplot(2,2,1)
imshow(mat2gray(im1))
subplot(2,2,2)
imshow(mat2gray(im2))
subplot(2,2,3)
imshow(mat2gray(im1_sampled))
subplot(2,2,4)
imshow(mat2gray(im2_sampled))
