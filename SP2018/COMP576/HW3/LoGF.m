function val = LoGF(u,v,s)
%LOGF Summary of this function goes here
%   Detailed explanation goes here

val = -exp(-(u.^2+v.^2)*s^2/2)*s^2*(u.^2+v.^2);

end

