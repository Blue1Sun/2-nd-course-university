function [ a, b, c ] = vlength( A, B, C )
AB = [B(1,1)-A(1,1); B(1,2)-A(1,2)];
BC = [C(1,1)-B(1,1); C(1,2)-B(1,2)];
CA = [C(1,1)-A(1,1); C(1,2)-A(1,2)];
a = sqrt(AB(1,1)^2+AB(2,1)^2);
b = sqrt(BC(1,1)^2+BC(2,1)^2);
c = sqrt(CA(1,1)^2+CA(2,1)^2);
end

