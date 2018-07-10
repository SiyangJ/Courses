ntest = 1000;
errs = zeros(ntest);
cnd = 200;
mt = 100;
nt = 20;
for i=1:ntest
    
    % Generate random matrix A, starting with the SVD of a random matrix
    A=randn(mt,nt);
    [u,s,v]=svd(A);
    % Let singular values range from 1 to cnd, with
    % uniformly distributed logarithms
    sd = [1, cnd, exp(rand(1,nt-2)*log(cnd))];
    s = diag(sd);
    A=u(:,1:nt)*s*v';
    
    errs(i) = max(max(abs(eye(mt)-A*(A'*A)^-1*A')));
end
    