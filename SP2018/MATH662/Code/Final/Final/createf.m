function [f,f_loc] = createf(func,N,t0,tf)

h = (tf-t0)/N;
[X,Y] = meshgrid(linspace(t0,tf,N+1),linspace(t0,tf,N+1));
f = func(X,Y);
f_loc = [0;0;h;h];

end