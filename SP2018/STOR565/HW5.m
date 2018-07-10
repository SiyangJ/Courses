X1 = [3,2,4,1,2,4,4]';
X2 = [4,2,4,4,1,3,1]';
Y = [true,true,true,true,false,false,false]';

X = [X1,X2];

mdl = fitcsvm(X,Y);