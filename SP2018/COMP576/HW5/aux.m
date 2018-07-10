
for l = 5:8
P = im2double(imread(sprintf('im%d.jpg',l)));
[n,m]=size(P);
o = min(n,m);
P = P(1:o,1:o);
%imshow(mat2gray(P))
v = 2^floor(log2(o));
P = imresize(P,[v,v]);
imwrite(P,sprintf('img%dc.jpg',l))
end

%%
t1 = 4.5;
dt = 8;

nctrl = 8;

ts = t1:dt:t1+(nctrl-1)*dt;

f = @(x) x.^4-60*x.^3-70*x+4;

ctrls = f(ts);

xs = 1:80;

vals = CubicBSpline1D(ctrls,t1,dt,xs);

figure
hold on
plot(xs,vals)
fplot(f,[0,80])
hold off

%%

[X,Y] = meshgrid(1:100,1:100);

[XX,YY] =meshgrid(5.5:10:95.5,5.5:10:95.5);

g = @(x,y) (x-50).^2+(y-50).^2;

GG = g(XX,YY);

G = g(X,Y);

G_ = CubicBSpline2D(GG,XX(1),YY(1),10,10,1:100,1:100);

figure
subplot(1,2,1)
surf(X,Y,G)
subplot(1,2,2)
surf(X,Y,G_)
view(3)
%%
Lnonpos = L<=0;
Lneg = L<0;
LIntNonpos = L(boxdim/2:end-boxdim/2,boxdim/2:end-boxdim/2)<=0;
LIntNeg = L(boxdim/2:end-boxdim/2,boxdim/2:end-boxdim/2)<0;

[rowIntNeg,colIntNeg] = find(LIntNeg);

%%
t1 = boxdim/2+0.5; 
dt = boxdim;

testCol = colIntNeg(30)+31;

figure
hold on
plot(I(:,testCol),'--')
plot(t1:dt:t1+7*dt,med(:,testCol),'-o')
plot(L(:,testCol),'-')
hold off
legend({'I','med','L'})

%%
p = 1;
LIntIntNonpos = L(boxdim*p+1:end-boxdim*p,boxdim*p+1:end-boxdim*p)<=0;
LIntIntNeg = L(boxdim*p+1:end-boxdim*p,boxdim*p+1:end-boxdim*p)<0;

[rowIntIntNeg,colIntIntNeg] = find(LIntIntNeg);
[rowIntIntNonpos,colIntIntNonpos] = find(LIntIntNonpos);

size(rowIntIntNeg,1)
size(rowIntIntNonpos,1)

%%
imshow(mat2gray(R(boxdim*p+1:end-boxdim*p,boxdim*p+1:end-boxdim*p)))