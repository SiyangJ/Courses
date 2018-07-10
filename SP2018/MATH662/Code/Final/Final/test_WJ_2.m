figure
hold on
for N = [4,8,16,32,128]
%%
X = zeros(N+1,N+1);
Y = X;
r = X;

[f,f_loc] = createf(f_func,N,t0,tf);

h = f_loc(end);

rhs = -h^2*f;

errors_ = zeros(1,ncycle+1);

arr_size = (N+1)^2;

rhs_ = reshape(rhs,[1,arr_size]);

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

X = X.*0;
Y = Y.*0;

input = reshape(r,[1,arr_size]);
output = zeros(1,arr_size);

for k=1:Nb

    dim = N+1;
    curp = 1;
    wd4 = w/4;
    % i=0;
    for j=0:N    
        output(curp)=0;
        curp = curp+1;
    end
    
    for i=1:N-1
        % j=0;
        output(curp) = 0;
        curp=curp+1;
        for j=1:N-1
        
            output(curp) = (1-w)*input(curp) +...
                            wd4*(input(curp+1) +...
                                 input(curp-1) +...
                                 input(curp+dim) +...
                                 input(curp-dim) +...
                                 rhs_(curp));
            curp = curp+1;
        end
        % j=N;
        output(curp) = 0;
        curp = curp+1;
    end
    % i=N;
    for j=0:N    
        output(curp)=0;
        curp = curp+1;
    end
end

X = reshape(output,[N+1,N+1]);

X = X_-X;

end
%%
errors_ = errors_/h^2;
plot(errors_)
end
hold off