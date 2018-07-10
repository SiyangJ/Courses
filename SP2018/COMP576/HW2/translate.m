function res = translate(img,dx,dy)

[m,n]=size(img);

res = zeros(m,n);

for i=1:m
    for j=1:n
        i_ = mod(i+dy,m);
        if i_==0
            i_=m;
        end
        j_ = mod(j+dx,n);
        if j_==0
            j_=n;
        end
        res(i_,j_) = img(i,j);
    end
end

end