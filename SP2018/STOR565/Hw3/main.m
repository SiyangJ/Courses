f1 = @(y)LassoBeta(y,1);
f2 = @(y)LassoBeta(y,5);
f3 = @(y)LassoBeta(y,10);

X = -10:0.01:10;

Y1 = arrayfun(f1,X);
Y2 = arrayfun(f2,X);
Y3 = arrayfun(f3,X);

plot(X,Y1,X,Y2,X,Y3)