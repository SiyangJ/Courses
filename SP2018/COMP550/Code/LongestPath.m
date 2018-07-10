s = 'character';
n = length(s);

P = ones(n,n);
D = zeros(n,n);
% 1 is down, -1 is left, 0 is left-down
for i=1:n-1
    if s(i)==s(i+1)
        P(i,i+1)=2;
    end
end

for l=3:n
    for i=1:n-l+1
        j=i+l-1;
        if s(i)==s(j)
            P(i,j)=2+P(i+1,j-1);
        else
            a=P(i+1,j);
            b=P(i,j-1);
            if a>b
                D(i,j)=1;
                P(i,j)=P(i+1,j);
            else
                D(i,j)=-1;
                P(i,j)=P(i,j-1);
            end
        end
    end
end

% j=n;
% i=1;
% while j>i
%     
%     
%     
%     
% end
                
                        
            