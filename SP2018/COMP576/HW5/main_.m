I = im2double(imread('img7c.jpg'));

dim = size(I,1);

nbox = 8;

boxdim = dim/nbox;

ctrl = zeros(nbox,nbox);

for i=1:nbox
    for j=1:nbox
        
        ctrl(i,j) = mean(mean(I((i-1)*boxdim+1:i*boxdim,(j-1)*boxdim+1:j*boxdim)));
        
    end 
end

global med

L = CubicBSpline2D(ctrl,boxdim/2+0.5,boxdim/2+0.5,boxdim,boxdim,1:dim,1:dim);

L = mat2gray(L);
%R = mat2gray(I./L);

R = I./L;


%R = I./max(0.1,L);

%I_ = R.*L;
%%
figure
subplot(1,3,1)
imshow(mat2gray(I));
subplot(1,3,2)
imshow(mat2gray(L));
subplot(1,3,3)
imshow(mat2gray(R));
%subplot(1,4,4)
%imshow(mat2gray(I_));
