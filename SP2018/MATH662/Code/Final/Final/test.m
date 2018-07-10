Na = 6;
Nb = 6;
omega = 2/3;
ncycle = 10;
f_func = @(x,y) rand(size(x));
N = 16;
[f,f_loc] = createf(f_func,N,t0,tf);
save('Input.mat','-v4')
%%
%f_func = @(x,y) exp(-((x-50).^2+(y-50).^2)/2);
f_func = @(x,y) 1000*exp(-((x-50).^2+(y-50).^2)/2/50^2);

t0 = 0;
tf = 100;

N = 4;
Na = 5;
Nb = 5;
omega = 2/3;
ncycle = 10;

[f,f_loc] = createf(f_func,N,t0,tf);

    save('Input.mat','-v4')
    system('./main')
    load('Output.mat','errors')
    
%%

X = zeros(N+1,N+1);
Y = X;
r = X;

errors_ = zeros(1,Nb/2+1);

for i=2:N
    for j=2:N
        r(i,j) = 4*X(i,j)-X(i-1,j)-X(i+1,j)-X(i,j-1)-X(i,j+1)-rhs(i,j);
    end
end
errors_(1) = max(max(abs(r)));

for k=1:Nb/2

for i=2:N
    for j=2:N
        Y(i,j) = (1-w)*X(i,j)+w/4*...
                (X(i+1,j)+X(i-1,j)+X(i,j-1)+X(i,j+1)+rhs(i,j));
    end
end
for i=2:N
    for j=2:N
        X(i,j) = (1-w)*Y(i,j)+w/4*...
                (Y(i+1,j)+Y(i-1,j)+Y(i,j-1)+Y(i,j+1)+rhs(i,j));
    end
end

for i=2:N
    for j=2:N
        r(i,j) = 4*X(i,j)-X(i-1,j)-X(i+1,j)-X(i,j-1)-X(i,j+1)-rhs(i,j);
    end
end
errors_(k+1) = max(max(abs(r)));

end
figure
plot(errors_)
