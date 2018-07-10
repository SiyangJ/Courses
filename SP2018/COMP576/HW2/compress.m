function res = compress(img,m)
%CONPRESS Summary of this function goes here
%   Detailed explanation goes here

n = size(img,1);

d = n/m;

res = zeros(m);

for i=1:m
    for j=1:m
        res(i,j) = img(1+floor(d*(i-1)),1+floor(d*(j-1)));
    end
end

end

