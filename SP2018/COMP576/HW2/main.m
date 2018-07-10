%% Preparation
dim = 128;

img1 = imread('img1.jpg');
img2 = imread('img2.jpg');

img2 = rgb2gray(img2);

img1 = im2double(img1);
img2 = im2double(img2);

%imshow(img2)

img1 = compress(img1,128);
img2 = compress(img2,128);

imwrite(img1,'img1c.jpg');
imwrite(img2,'img2c.jpg');

%% 1

A = img1;
B = img2;

[Aa,Ap] = AmpPhaseDFT(A);
[Ba,Bp] = AmpPhaseDFT(B);

Ar = ReconfromAmpPhase(Aa,Ap);
Br = ReconfromAmpPhase(Ba,Bp);

Ad = Ar-A;
Bd = Br-B;

ADiff1 = norm(Ad,1);
BDiff1 = norm(Bd,1);

%% 2

AAPB = ReconfromAmpPhase(Aa,Bp);
ABPA = ReconfromAmpPhase(Ba,Ap);

% figure
% imshow(AAPB)
% figure
% imshow(ABPA)

stronger = 'Phase';

%% 3

dx = 10;
dy = 0;
As1 = translate(A,dx,dy);
dy = 20;
As2 = translate(A,dx,dy);

[As1a,As1p] = AmpPhaseDFT(As1);
[As2a,As2p] = AmpPhaseDFT(As2);

As1ad = As1a - Aa;
As2ad = As2a - Aa;

As1pd = As1p - Ap;
As2pd = As2p - Ap;

As1aDiffF = norm(As1ad,'fro');
As2aDiffF = norm(As2ad,'fro');
As1pDiffF = norm(As1ad,'fro');
As2pDiffF = norm(As2pd,'fro');

%%

A=img1;

del_x=0;
del_y=0;

dim=128;

As1 = [A(:,dim-del_x+1:dim),A(:,1:dim-del_x)];
    
AS = [As1(dim-del_y+1:dim,:);As1(1:dim-del_x,:)];
    
%%
figure
imshow(A)
figure
imshow(As1)
figure
imshow(AS)
