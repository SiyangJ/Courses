%%
cnd = 2000;
m = 100;
n = 20;
% Generate random matrix A, starting with the SVD of a random matrix
A=randn(m,n);
[u,s,v]=svd(A);
% Let singular values range from 1 to cnd, with
% uniformly distributed logarithms
sd = [1, cnd, exp(rand(1,n-2)*log(cnd))];
s = diag(sd);
A=u(:,1:n)*s*v';

b = rand(m,1);

[Q,R] = qr(A,0);
Rinv = R^-1;

Inv = [eye(m),Q*Rinv';Rinv*Q',-Rinv*Rinv'];

nstep = 200;

ress = zeros(1,nstep);
rest = zeros(1,nstep);

x = Rinv*Q'*b;
r = b-A*x;

for i=1:nstep
    s = b-r-A*x;
    t = -A'*r;
    ress(i)=norm(s);
    rest(i)=norm(t);
    d=Inv*[s;t];
    r = r+d(1:m);
    x = x+d(m+1:end);
end
%%
figure
subplot(1,2,1)
loglog(ress)
subplot(1,2,2)
loglog(rest)