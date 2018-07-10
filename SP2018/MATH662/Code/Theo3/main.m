samples = 50;
m = 20;
n = 20;
cnds = logspace(1,20,40);

ncnd = length(cnds);

maxOrths = zeros(ncnd,3);
maxRess = zeros(ncnd,3);

for i=1:ncnd
    [maxOrths(i,:),maxRess(i,:)] = QRS(m,n,cnds(i),samples);
end

%%
figure
hold on
for i=1:3
    plot(cnds,maxOrths(:,i),'-')
    plot(cnds,maxRess(:,i),'--')
end
hold off
legend({'HH-Or','HH-Re','CG-Or','CG-Re','MG-Or','MG-Re'})
set(gca,'XScale','log')
set(gca,'YScale','log')

%%
cnd = 2000;
m = 100;
n = 20;
% Generate random matrix A, starting with the SVD of a random matrix
A=randn(m,n);
%A = single(A);
[u,s,v]=svd(A);
% Let singular values range from 1 to cnd, with
% uniformly distributed logarithms
sd = [1, cnd, exp(rand(1,n-2)*log(cnd))];
s = diag(sd);
A=u(:,1:n)*s*v';

b = rand(m,1);

[Q,R] = qr(A,0);
Rinv = R^-1;

Inv = [eye(m)-A*(Rinv*Rinv')*A',Q*Rinv';Rinv*Q',-Rinv*Rinv'];

nstep = 200;

ress = zeros(1,nstep);
rest = zeros(1,nstep);

x = Rinv*Q'*b;
r = b-A*x;

for i=1:nstep
    %bt = double(b);
    %rt = double(r);
    %Ax = double(A*x);
    %s = bt-rt-Ax;
    %s = single(s);
    s = b-r-A*x;
    t = -A'*r;
    ress(i)=norm(s);
    rest(i)=norm(t);
    d = Inv*[s;t];
    r = r+d(1:m);
    x = x+d(m+1:end);
    %d=double(Inv*[s;t]);
    %r = single(double(r)+d(1:m));
    %x = single(double(x)+d(m+1:end));
end
