figure
hold on

for N = [4,8,16,32,128,256]

arr_size = (N+1)^2;

old = zeros(1,arr_size);
new = zeros(1,arr_size);

errors__ = zeros(1,Nb);

[f,f_loc] = createf(f_func,N,t0,tf);

h = f_loc(end);

rhs = -h^2*f;
rhs__ = reshape(rhs,[1,arr_size]);

for k=1:Nb

    dim = N+1;
    curp = 1;
    wd4 = w/4;
    % i=0;
    for j=0:N    
        new(curp)=0;
        curp = curp+1;
    end
    
    for i=1:N-1
        % j=0;
        new(curp) = 0;
        curp=curp+1;
        for j=1:N-1
        
            new(curp) = (1-w)*old(curp) +...
                            wd4*(old(curp+1) +...
                                 old(curp-1) +...
                                 old(curp+dim) +...
                                 old(curp-dim) +...
                                 rhs__(curp));
            curp = curp+1;
        end
        % j=N;
        new(curp) = 0;
        curp = curp+1;
    end
    % i=N;
    for j=0:N    
        new(curp)=0;
        curp = curp+1;
    end
 
    temp = old;
    old = new;
    new = temp;
    
X = reshape(old,[N+1,N+1]);
%%rhs_ = reshape(rhs__,[N+1,N+1]);
    
r = zeros(N+1,N+1);    
    
for i=2:N
    for j=2:N
        r(i,j) = 4*X(i,j)-X(i-1,j)-X(i+1,j)-X(i,j-1)-X(i,j+1)-rhs(i,j);
    end
end
errors__(k) = max(max(abs(r)));
  
end
%%
errors__ = errors__/h^2;
plot(errors__)
end
hold off
