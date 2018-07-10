load('images.mat','im_array')
im_array = im2double(im_array);

%%
rng(1);

dim = 128;

[n,d] = size(im_array);

ntrain = floor(3/4*n);
ntest = n-ntrain;

%indices = randperm(n);
indices = 1:n;
trainIndex = indices(1:ntrain);
trainImArr = im_array(trainIndex,:);

testIndex = indices(ntrain+1:end);
testImArr = im_array(testIndex,:);

%%

%[Utr,Str,Vtr] = svd(trainImArr,'econ');

[Utr,Str] = eig(trainImArr*trainImArr');
Str = diag(Str);
[~,piv] = sort(Str,'descend');

Vtr = trainImArr'*Utr;

Vtr = Vtr(:,piv);
Vtr = normc(Vtr);

eigFaceArr = zeros(dim,dim,ntrain);
for i=1:ntrain
    eigFaceArr(:,:,i) = reshape(Vtr(:,i),[128,128]);
end

%%

coeffArr = trainImArr * Vtr;

%%
j = 20;
recon0 = zeros(dim);
for k = 1:40
    recon0 = recon0 + coeffArr(j,k) * eigFaceArr(:,:,k);
end

%%

nuse = 40;

j0 = 45;
j1 = 26;

bk0 = coeffArr(j0,1:nuse);
bk1 = coeffArr(j1,1:nuse);

tt = 0:0.25:1;

nt = length(tt);
figure
for i = 1:nt
    im = (bk0 + (bk1-bk0)*tt(i)) * Vtr(:,1:nuse)';
    im = reshape(im,[dim,dim]);
    subplot(1,nt,i)
    imshow(im,[min(min(im)),max(max(im))]);
end

%%

q3 = 1:20;
testIms = testImArr(q3,:);
bks = testIms*Vtr;
nuse = 60;
reconIms = bks(:,1:nuse)*Vtr(:,1:nuse)';
errIms = reconIms-testIms;
errs = diag(errIms*errIms')/d;
SAMSE = sqrt(mean(errs));

%%
amare = mean(mean(abs((reconIms-testIms)./testIms)));

%%
%dim = 128;
ky = 0;
kx = 27/128;
kx2 = kx+1;

im4 = zeros(dim);
im42 = zeros(dim);

for i=1:dim
    for j=1:dim
        im4(i,j) = sin((ky*i+kx*j)*2*pi);
        im42(i,j) = sin((ky*i+kx2*j)*2*pi);
    end
end

figure
subplot(1,2,1)
imshow(im4,[min(min(im4)),max(max(im4))])
subplot(1,2,2)
imshow(im42,[min(min(im42)),max(max(im42))])

%%
fac = 4;
dimr = dim/fac;

im4r = zeros(fac);
im42r = zeros(fac);

for i=1:fac
    for j=1:fac
        im4r(i,j) = mean(mean(im4(dimr*(i-1)+1:dimr*i,dimr*(j-1)+1:dimr*j)));
        im42r(i,j) = mean(mean(im42(dimr*(i-1)+1:dimr*i,dimr*(j-1)+1:dimr*j)));
    end
end
figure
subplot(1,2,1)
imshow(im4r,[min(min(im4r)),max(max(im4r))])
subplot(1,2,2)
imshow(im42r,[min(min(im42r)),max(max(im42r))])

%%
sigma = 2;
aa = logspace(-1,1,10);
na = length(aa);
I = @(x,a) (1/sigma/sqrt(2*pi))*(exp(-(x+a).^2/2/sigma^2)+exp(-(x-a).^2/2/sigma^2));
range = [-5,5];
figure
for i=1:na
    subplot(1,na,i)
    fplot(@(x)I(x,aa(i)),range)
end
Ipp0 =@(a) exp(-a^2/2/sigma^2)*(a^2-sigma^2)*2/sqrt(2*pi)/sigma^5;
