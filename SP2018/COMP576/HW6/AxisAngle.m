v = quat2axang(q);
th = v(4);
v = v(1:3);

Av = [0,-v(1),v(2);...
      v(1),0,-v(3);...
      -v(2),v(3),0];


if th==0
    R = eye(3);
else
    R = eye(3)+sin(th)/th*Av+(1-cos(th))/th^2*Av^2;
end

