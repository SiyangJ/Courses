function vals = CubicBSpline2D(ctrls,t1x,t1y,dtx,dty,xs,ys)
%CUBICBSPLINE2D Summary of this function goes here
%   Detailed explanation goes here

nx = length(xs);
ny = length(ys);

[npy,npx] = size(ctrls);

global med

med = zeros(npy,nx);
vals = zeros(ny,nx);

for i=1:npy
    med(i,:) = CubicBSpline1D(ctrls(i,:),t1x,dtx,xs);
end

for i=1:nx
    vals(:,i) = CubicBSpline1D(med(:,i),t1y,dty,ys)';
end

end

