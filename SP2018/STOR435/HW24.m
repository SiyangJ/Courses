pxy = @(x,y) nchoosek(x,y)*4^-x*3^y/6;

%%
sumpxy = 0;
for x=1:6
    for y=0:x
        sumpxy = sumpxy+pxy(x,y);
    end
end

%%
py = zeros(1,7);
for y = 0:6
py(y+1) = 0;
for x=max(1,y):6
    py(y+1) = py(y+1)+pxy(x,y);
end
end
%%
ex3=0;
for x=3:6
    px3(x)=pxy(x,3)/py(4);
    ex3 = ex3+x*px3(x);
end

%%
A = [0.1,0.05,0;0.15,0.15,0;0.1,0.15,0.1;0,0.05,0.1;0,0,0.05];
px = sum(A,2);
py = sum(A,1);

xvals = (5:-1:1);
yvals = (4:-1:2);

xm = xvals*px;
ym = py*yvals';

x2m = xvals.^2*px;
y2m = py*yvals.^2';

varx = x2m-xm^2;
vary = y2m-ym^2;

XX = repmat(xvals',[1,3]);
YY = repmat(yvals,[5,1]);

EXY = sum(sum(XX.*YY.*A));

CovXY = EXY-xm*ym;

corr = CovXY/sqrt(varx*vary);

