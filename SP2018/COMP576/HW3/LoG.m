function val = LoG(x,y,s)

r = x^2+y^2;
ss = s^2;

val = (r-2*ss)/ss^2*exp(-r/2/ss);

end