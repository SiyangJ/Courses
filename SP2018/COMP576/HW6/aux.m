I = Ic;
Iind = find(I>0);
Ieff = I(Iind);
[x,y,z] = ind2sub(size(I),Iind);
scatter3(x,y,z,Ieff(:))
daspect([1,1,1])
xlabel('x')
ylabel('y')
zlabel('z')


%%
figure
imshow(mat2gray(Ia_disp))

%%

q = normr([0,0,1,0]);

u = [1,1,1];

u1 = quatmultiply(quatinv(q),quatmultiply([0,u],q));
u1 = u1(2:4);

u2 = quatrotate(q,u);