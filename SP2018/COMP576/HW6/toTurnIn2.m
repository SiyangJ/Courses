dims = [16,16,16];

z_index = 6;
c_x = 8;
c_y = 8; 
c_z = 8;
r_x = 3;
r_y = 4;
r_z = 5;
theta = pi/4;

v = [1,0,0];

%%
    %z_index is the index for the slice
    %c_x is the center in the x
    %c_y is the center in the y
    %c_z is the center in the z
    %r_x is the radius in the x
    %r_y is the radius in the y
    %r_z is the radius in the z
    %theta is the angle of rotation
    %z_slice %slice at z_index of ellipsoid
    %z_rotated_slice%slice at z_index of rotated ellipsoid
    %q %quaternion, vector with 4 values
    %R %rotation matrix, 3x3
    %d %center of mass, vector with 3 values
    %A %second moment, 3x3
    
c = [c_x,c_y,c_z];
r = [r_x,r_y,r_z];

q = [cos(theta/2),sin(theta/2)*v];
        
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

z_slice = Ia(:,:,z_index);

%% Input b, c

g = -c;

% I -> I~, where I~(x) = I(x-g), or I~(x+g) = I(x);
% I~ -> I^, where I^(x') = I~(x), M: x'->x
% I^ -> I', where I'(x) = I^(x+g), or I'(x-g) = I^(x);

q = normr(q);

% p = [q(1),-q(2:4)];
p = q;

% (0,u') = p*(0,u)*p^-1
% is equivalent to u'=R*u
% if R is defined as follows
R = [p(1)^2+p(2)^2-p(3)^2-p(4)^2, 2*(p(2)*p(3)-p(1)*p(4))    , 2*(p(1)*p(3)+p(2)*p(4));...
     2*(p(2)*p(3)+p(1)*p(4))    , p(1)^2-p(2)^2+p(3)^2-p(4)^2, 2*(p(3)*p(4)-p(1)*p(2));...
     2*(p(2)*p(4)-p(1)*p(3))    , 2*(p(3)*p(4)+p(1)*p(2))    , p(1)^2-p(2)^2-p(3)^2+p(4)^2];

[I,J,K] = ind2sub(dims,1:prod(dims));
IJK = [I;J;K] + g';
ORI = R*IJK - g';

Ic1 = interp3(Ia,ORI(2,:),ORI(1,:),ORI(3,:));
Ic1(isnan(Ic1))=0;

Ic = reshape(Ic1,dims);

z_rotated_slice = Ic(:,:,z_index);

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

%A = A/w;