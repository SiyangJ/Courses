%% Input a

c = [60,70,64];
r = [10,30,40];

cz = 64;

%% Other Parameters

dims = [128,128,128];

f = @(X) sum(((X-c)./r).^2)-1;

F = @(X) double(f(X)<=0);

corners = zeros(dims+1);

% Need to optimize
for i = 1:dims(1)+1
    for j = 1:dims(2)+1
        for k = 1:dims(3)+1            
            corners(i,j,k) = F([i,j,k]-1/2);            
        end
    end
end

Ia = zeros(dims);

% Need to optimize
for i = 1:dims(1)
    for j = 1:dims(2)
        for k = 1:dims(3)
            Ia(i,j,k) = ...
            corners(i  ,j  ,k  )+...
            corners(i  ,j  ,k+1)+...
            corners(i  ,j+1,k  )+...
            corners(i  ,j+1,k+1)+...
            corners(i+1,j  ,k  )+...
            corners(i+1,j  ,k+1)+...
            corners(i+1,j+1,k  )+...
            corners(i+1,j+1,k+1);
        end
    end
end

Ia_disp = Ia(:,:,cz);

%% Input b, c

g = -c;

q = axang2quat([0,0,1,0]);

%q = normr([1,2,3,4]);

% I -> I~, where I~(x) = I(x-g), or I~(x+g) = I(x);
% I~ -> I^, where I^(x') = I~(x), M: x'->x
% I^ -> I', where I'(x) = I^(x+g), or I'(x-g) = I^(x);

q = normr(q);

p = [q(1),-q(2:4)];

% (0,u') = p*(0,u)*p^-1
% is equivalent to u'=M*u
% if M is defined as follows
M = [p(1)^2+p(2)^2-p(3)^2-p(4)^2, 2*(p(2)*p(3)-p(1)*p(4))    , 2*(p(1)*p(3)+p(2)*p(4));...
     2*(p(2)*p(3)+p(1)*p(4))    , p(1)^2-p(2)^2+p(3)^2-p(4)^2, 2*(p(3)*p(4)-p(1)*p(2));...
     2*(p(2)*p(4)-p(1)*p(3))    , 2*(p(3)*p(4)+p(1)*p(2))    , p(1)^2-p(2)^2-p(3)^2+p(4)^2];

[I,J,K] = ind2sub(dims,1:prod(dims));
IJK = [I;J;K] + g';
ORI = M*IJK - g';

Ic1 = interp3(Ia,ORI(2,:),ORI(1,:),ORI(3,:));
Ic1(isnan(Ic1))=0;

Ic = reshape(Ic1,dims);

%% d 1)

w = sum(sum(sum(Ic)));

[XX,YY,ZZ] = meshgrid(1:dims(1),1:dims(2),1:dims(3));

dx = sum(sum(sum(Ic.*XX)))/w;
dy = sum(sum(sum(Ic.*YY)))/w;
dz = sum(sum(sum(Ic.*ZZ)))/w;

d = [dy,dx,dz];
ce = d-g;

%% d 2)

A = zeros(3);

for i = 1:dims(1)
    for j = 1:dims(2)
        for k = 1:dims(3)
            x = [i,j,k];
            A = A + Ic(i,j,k)*(x-d)'*(x-d);
        end
    end
end

A = A/w;