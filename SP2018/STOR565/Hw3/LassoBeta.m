function b = LassoBeta(y,l)
%LASSOBETA Summary of this function goes here
%   Detailed explanation goes here

lim = l/2;

if y<= -lim
    b=y+lim;
elseif y>= lim
    b=y-lim;
else
    b=0;
end     

end

