gfunc = @(x,y) x^3*y;
[nx,ny]=size(f);
nx=nx-2;
ny=ny-2;
N = nx*ny;
h = 0.025;

v = ones(1,nx);
v(end)=0;
v = repmat(v,1,ny);
v = v(1:end-1);

A = diag(-4*ones(1,N))+diag(v,1)+diag(v,-1)+...
    diag(ones(1,N-nx),nx)+diag(ones(1,N-nx),-nx);

xx = 0:h:(nx+1)*h;
yy = 0:h:(ny+1)*h;

RHSf = h^2*f(2:end-1,2:end-1);

RHSg = zeros(nx,ny);

RHSg(:,1) = RHSg(:,1)-arrayfun(@(x)gfunc(x,0),xx(2:end-1))';
RHSg(:,end) = RHSg(:,end)-arrayfun(@(x)gfunc(x,yy(end)),xx(2:end-1))';
RHSg(1,:) = RHSg(1,:)-arrayfun(@(y)gfunc(0,y),yy(2:end-1));
RHSg(end,:) = RHSg(end,:)-arrayfun(@(y)gfunc(xx(end),y),yy(2:end-1));

RHSgr = reshape(RHSg,[N 1]);
RHSfr = reshape(RHSf,[N 1]);

%%
%RHSr = reshape(RHS,[N,1]);
RHSr = RHSfr + RHSgr;
%%
U = A\RHSr;
%%
Ur = reshape(U,[nx,ny]);
%%
imshow(Ur,[min(min(Ur)),max(max(Ur))])
