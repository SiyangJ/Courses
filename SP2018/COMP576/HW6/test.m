q0 = sym('q0','real');
q1 = sym('q1','real');
q2 = sym('q2','real');
q3 = sym('q3','real');
u1 = sym('u1','real');
u2 = sym('u2','real');
u3 = sym('u3','real');

qsym = [q0,q1,q2,q3];
qsyminv = [q0,-q1,-q2,-q3];
usym = [0,u1,u2,u3];
res1 = quatmultiply(qsym,usym);
res2 = quatmultiply(res1,qsyminv);
%%

qq = axang2quat([1,1,0,pi/2]);

x1 = (0:10)';
y1 = x1;
z1 = x1;

mat1 = [x1,y1,z1];

x2 = x1;
y2 = x1;
z2 = zeros(11,1);

mat2 = [x2,y2,z2];

x3 = 10*ones(11,1);
y3 = x3;
z3 = x1;

mat3 = [x3,y3,z3];

mat1q = quatrotate(qq,mat1);
x1q = mat1q(:,1);
y1q = mat1q(:,2);
z1q = mat1q(:,3);

mat2q = quatrotate(qq,mat2);
x2q = mat2q(:,1);
y2q = mat2q(:,2);
z2q = mat2q(:,3);

mat3q = quatrotate(qq,mat3);
x3q = mat3q(:,1);
y3q = mat3q(:,2);
z3q = mat3q(:,3);

figure
hold on
plot3(x1,y1,z1,'r-')
plot3(x2,y2,z2,'r-')
plot3(x3,y3,z3,'r-')
plot3(x1q,y1q,z1q,'b-')
plot3(x2q,y2q,z2q,'b-')
plot3(x3q,y3q,z3q,'b-')
hold off
xlabel('x')
ylabel('y')
zlabel('z')
daspect([1,1,1])
view(3)

%%
tic
ori = (M*[i,j,k]')' - g;
            if ori(1)>dims(1) || ori(2)>dims(2) || ori(3)>dims(3)
                Ic(i,j,k) = 0;
            else
                Ic(i,j,k) = interp3(Ia,ori(1),ori(2),ori(3));
            end
            toc

