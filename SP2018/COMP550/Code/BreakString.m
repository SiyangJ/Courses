function [c,B] = BreakString(n,L)
%BREAKSTRING Summary of this function goes here
%   Detailed explanation goes here

m = length(L);
B = zeros(1,m);
% 
% L(2:m+1) = L;
% L(1) = 0;
% L(m+2) = n+1;
% m = m+2;

P = zeros(m);
S = zeros(m);

P(1,1)=L(2);
for i=2:m-1
    P(i,i)=L(i+1)-L(i-1);
end
P(m,m)=n-L(m-1);

for l=2:m
    for i=1:m-l+1
        j=i+l-1;
        P(i,j)=Inf;
        for k=i:j-1
            q=P(i,k-1)+P(k+1,j);
            if q<P(i,j)
                P(i,j)=q;
                S(i,j)=k;
            end
        end
    end
end

c = P(1,m);

end

