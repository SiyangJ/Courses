v0 = [1,2,3,4,5];
v1 = [38,16,41,44,19,27,7,17,42,7,30,5,4,25,11];
v2 = [39,19,12,20,4,6,47,47,28,2];
v3 = [20	2	45	47	24	24	16	45	18	5];
v4 = [42	31	17	25	20	3	11	6	9	11];
v = v1;

%%
n = length(v);
m = zeros(n);
f = zeros(n);
s = zeros(n);

for i=1:n
    m(i,i)=0;
    f(i,i)=v(i);
    for j=i+1:n
        f(i,j)=mod(f(i,j-1)+v(j),50);
    end
end

for l=2:n
    for i=1:n-l+1
        j=i+l-1;
        m(i,j)=Inf;
        for k=i:j-1
            q = m(i,k)+m(k+1,j)+f(i,k)*f(k+1,j);
            if q<m(i,j)
                m(i,j)=q;
                s(i,j)=k;
            end
        end
    end
end
%%
disp(m(1,n))
            
            
            