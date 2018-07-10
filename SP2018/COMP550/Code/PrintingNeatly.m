n = 50;
M = 20;
word = '123456789';
L = randi(5,[1,n]);
W = cell(1,n);
for i=1:n
    W{i}=word(1:L(i));
end
%%

Cost = zeros(1,n);
NextLine = zeros(1,n);
NextLine(n)=0;
Cost(n)=0;
for i = linspace(n-1,1,n-1)
    r=M+1;
    Cost(i)=Inf;
    for j=i:n
        r=r-1-L(j);
        if r<0
            break;
        end
        if j==n
            Cost(i)=0;
            NextLine(i)=j+1;
            break;
        end
        c=r^3+Cost(j+1);
        if c<Cost(i)
            Cost(i)=c;
            NextLine(i)=j+1;
        end
    end
end

current=1;
while current<=n
    next=NextLine(current);
    for i=current:next-1
        fprintf(W{i})
        fprintf(' ')
    end
    if next<=n
        fprintf(W{current})
    end
    fprintf('\n')
    current=next;
end
        