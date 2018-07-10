figure
hold on

for N = [4,8,16,32,128,256]
%%
X = zeros(N+1,N+1);
Y = X;
r = X;

[f,f_loc] = createf(f_func,N,t0,tf);

h = f_loc(end);

rhs = -h^2*f;

ncycle = N;

errors_ = zeros(1,ncycle+1);

for l=1:ncycle+1
    
for i=2:N
    for j=2:N
        r(i,j) = 4*X(i,j)-X(i-1,j)-X(i+1,j)-X(i,j-1)-X(i,j+1)-rhs(i,j);
    end
end
errors_(l) = max(max(abs(r)));

if l>ncycle
    break;
end

X_ = X;

X = zeros(1,(N+1)^2);
Y = zeros(1,(N+1)^2);

for k=1:Nb/2

for i=2:N
    for j=2:N
        Y(i,j) = (1-w)*X(i,j)+w/4*...
                (X(i+1,j)+X(i-1,j)+X(i,j-1)+X(i,j+1)+r(i,j));
    end
end
for i=2:N
    for j=2:N
        X(i,j) = (1-w)*Y(i,j)+w/4*...
                (Y(i+1,j)+Y(i-1,j)+Y(i,j-1)+Y(i,j+1)+r(i,j));
    end
end
end

X = reshape(X,[N+1,N+1]);

X = X_-X;

end
%%
errors_ = errors_/h^2;
plot(errors_)
end
hold off