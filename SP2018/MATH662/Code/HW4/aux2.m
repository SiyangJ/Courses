Ans = magic(5);
h = 1;
gfunc = @(x,y) Ans(x+1,y+1);

f = del2(Ans,1);