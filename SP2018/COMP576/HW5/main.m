img1=imread('img7c.jpg');
%extract only grayscale images from rgb images
img1 = im2double(img1);
M = zeros(8,8);
for i = 1:64:512
    for j = 1:64:512
        average = mean(mean(img1(i:(i+64-1),j:(j+64-1))));
        M(idivide(int32(i),int32(64),'ceil'),idivide(int32(j),int32(64),'ceil'))= average;
    end
end


%%%lambda = [-1,3,-3,1;3,-6,3,0;-3,0,3,0;1,4,1,0];
lambda = [-1,3,-3,1;3,-6,3,0;-3,0,3,0;1,4,1,0]/6;

t_i = zeros(1,8);
for i= 1:8
    t_i(i) = 32.5+64*(i-1);
end

interMx = zeros(8,512);
for i =1:8
    [interMx(i,:),cps] = OneDSpline(t_i,lambda,M(i,:));
end

L = zeros(512,512);
for i = 1:512
    L(:,i) = (OneDSpline(t_i,lambda,interMx(:,i))).';
end
R = mat2gray(img1)./mat2gray(L);
function [splinedRow,cps] = OneDSpline(t_i,lambda,cps)
    %%%cp = [0;0;0;0];
    %%%idx = [0,0,0,1];
    splinedRow = zeros(1,512);
    
    k=2;
    for t = 1:512
        if t<t_i(k)+64 || k ==6
            %%%%%%%%%%%%%%%%%%%%%%%%
            idx = [((t-t_i(k))/64)^3, ((t-t_i(k))/64)^2, (t-t_i(k))/64, 1];
            %%dx = (t-t_i(k))/64;
            %%idx = [dx^3,dx^2,dx,1];
            cp = [cps(k-1);cps(k);cps(k+1);cps(k+2)];
            splinedRow(t) = (1/6)*idx*lambda*cp;
            %%A = lambda*cp;
            %%splinedRow(t) = idx*A;
        else
            k = k+1;
            %%%%%%%%%%%%%%%%%%%%%%%%
            idx = [((t-t_i(k))/64)^3, ((t-t_i(k))/64)^2, (t-t_i(k))/64, 1];
            %%dx = (t-t_i(k))/64;
            %%idx = [dx^3,dx^2,dx,1];
            cp = [cps(k-1);cps(k);cps(k+1);cps(k+2)];
            splinedRow(t) = (1/6)*idx*lambda*cp;
            %%A = lambda*cp;
            %%splinedRow(t) = idx*A;
        end
    end
end











