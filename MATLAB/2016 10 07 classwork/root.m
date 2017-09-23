function [x1,x2] = root(a, b, c)
d = (b^2 - 4*a*c);
d = sqrt(d);
x1 = (-b + d)/(2*a);
x2 = (-b - d)/(2*a);
end