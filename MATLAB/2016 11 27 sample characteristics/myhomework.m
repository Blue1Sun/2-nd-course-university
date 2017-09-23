function [] = myhomework(x)

n = length(x); %������ �������

fprintf('������ n = %d\n', n)

%������� ��������������
k = arif_mean(x, n); %���� �������
kk = mean(x); %���������� �������
fprintf('\n��. �������������� = %f (���� �.) = %f(�����. �.)\n', k, kk)

%���������� ���������
s2 = varian(x, k, n); %���� �������
ss2 = var(x); %���������� �������
fprintf('���������� ��������� = %f (���� �.) = %f(�����. �.)\n', s2, ss2)

%����������� ����������
s = stand_deviation(s2); %���� �������
ss = std(x); %���������� �������
fprintf('����������� ���������� = %f (���� �.) = %f(�����. �.)\n', s, ss)

%����������� ��������
v = coeff_variation(s, k); %���� �������
fprintf('����������� �������� = %f\n\n', v)

%��������� � ����������� �������
for i = 1:1:4
    a = starting_moment(x,i,n);
    fprintf('��������� ������ #%d = %f\n', i, a)
    b = central_moment(x,i,n);
    fprintf('����������� ������ #%d = %f\n\n', i, b)
end

%������ ������������ ����������
Sk = koef_asimm(x, n); %���� �������
SSk = skewness(x, 0); %���������� �������
fprintf('����������� ���������� = %f (���� �.) = %f(�����. �.)\n', Sk, SSk)

%������ ��������
Ex = exscess(x, n); %���� �������
EEx = kurtosis(x, 0) - 3; %���������� �������
fprintf('����������� ������� = %f (���� �.) = %f(�����. �.)\n', Ex, EEx)

%���������� ����
M = mode(x); %���������� �������
fprintf('\n���� = %f\n', M)

%���������� �������
Medx = median(x); %���������� �������  
fprintf('������� = %f\n', Medx)

hist(x,n)  
end

%������� ��������������
function [l] = arif_mean(x, n)
sum = 0;
for i = 1:1:n
    sum = sum + x(i);
end
l = sum/n;
end

%���������� ���������
function [s2] = varian(x, k, n)
s2 = 0;
for i = 1:1:n
    s2 = s2 + (x(i) - k)^2;
end;
s2 = s2/(n-1);
end

%����������� ����������
function [s] = stand_deviation(s2)
s = sqrt(s2);
end

%����������� ��������
function [v] = coeff_variation(s, k)
v = s/k;
end

%��������� ������ 
function [a] = starting_moment(x, l, n)
a = 0;
for i = 1:1:n
    a = a + x(i)^l;
end
a = 1/n*a;
end

%����������� ������
function [b] = central_moment(x, l, n)
b = 0;
for i = 1:1:n
    b = b + (x(i) - arif_mean(x, n))^l;
end
b = 1/n*b;
end

%������ ������������ ����������
function [Sk] = koef_asimm(x, n)
Sk = central_moment(x, 3, n)/(central_moment(x, 2, n))^(3/2);
end

%������ ��������
function [Ex] = exscess(x, n)
Ex =  central_moment(x, 4, n)/central_moment(x, 2, n)^2 - 3;
end