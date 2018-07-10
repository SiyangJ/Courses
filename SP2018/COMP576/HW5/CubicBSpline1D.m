function vals = CubicBSpline1D(ctrls,t1,dt,xs)
%BSPLINE Summary of this function goes here
%   Detailed explanation goes here

M = [-1, 3,-3, 1;...
      3,-6, 3, 0;...
     -3, 0, 3, 0;...
      1, 4, 1, 0]/6;
  
nctrl = length(ctrls);
k = 1;
nx = length(xs);
vals = zeros(1,nx);

t = t1;
A = zeros(4,1);
for i=2:nctrl-2
    t = t+dt;
    A = M*[ctrls(i-1);ctrls(i);ctrls(i+1);ctrls(i+2)];
    while xs(k)<t+dt
        dx = (xs(k)-t)/dt;
        vals(k)=[dx^3,dx^2,dx,1]*A; 
        k = k+1;
    end
end

while k<=nx
    dx = (xs(k)-t)/dt;
    vals(k)=[dx^3,dx^2,dx,1]*A;
    k = k+1;
end

end

