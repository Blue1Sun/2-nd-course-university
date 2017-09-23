function [] = myhomework(x)

n = length(x); %размер матрицы

fprintf('Размер n = %d\n', n)

%СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ
k = arif_mean(x, n); %своя функция
kk = mean(x); %встроенная функция
fprintf('\nСр. арифметическое = %f (своя ф.) = %f(внутр. ф.)\n', k, kk)

%ВЫБОРОЧНАЯ ДИСПЕРСИЯ
s2 = varian(x, k, n); %своя функция
ss2 = var(x); %встроенная функция
fprintf('Выборочная дисперсия = %f (своя ф.) = %f(внутр. ф.)\n', s2, ss2)

%СТАНДАРТНОЕ ОТКЛОНЕНИЕ
s = stand_deviation(s2); %своя функция
ss = std(x); %встроенная функция
fprintf('Стандартное отклонение = %f (своя ф.) = %f(внутр. ф.)\n', s, ss)

%КОЭФФИЦИЕНТ ВАРИАЦИИ
v = coeff_variation(s, k); %своя функция
fprintf('Коэффициент вариации = %f\n\n', v)

%НАЧАЛЬНЫЕ И ЦЕНТРАЛЬНЫЕ МОМЕНТЫ
for i = 1:1:4
    a = starting_moment(x,i,n);
    fprintf('Начальный момент #%d = %f\n', i, a)
    b = central_moment(x,i,n);
    fprintf('Центральный момент #%d = %f\n\n', i, b)
end

%ОЦЕНКА КОЭФФИЦИЕНТА АСИММЕТРИИ
Sk = koef_asimm(x, n); %своя функция
SSk = skewness(x, 0); %встроенная функция
fprintf('Несмещенная асимметрия = %f (своя ф.) = %f(внутр. ф.)\n', Sk, SSk)

%ОЦЕНКА ЭКСЦЕССА
Ex = exscess(x, n); %своя функция
EEx = kurtosis(x, 0) - 3; %встроенная функция
fprintf('Несмещенный эксцесс = %f (своя ф.) = %f(внутр. ф.)\n', Ex, EEx)

%ВЫБОРОЧНАЯ МОДА
M = mode(x); %встроенная функция
fprintf('\nМода = %f\n', M)

%ВЫБОРОЧНАЯ МЕДИАНА
Medx = median(x); %встроенная функция  
fprintf('Медиана = %f\n', Medx)

hist(x,n)  
end

%СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ
function [l] = arif_mean(x, n)
sum = 0;
for i = 1:1:n
    sum = sum + x(i);
end
l = sum/n;
end

%ВЫБОРОЧНАЯ ДИСПЕРСИЯ
function [s2] = varian(x, k, n)
s2 = 0;
for i = 1:1:n
    s2 = s2 + (x(i) - k)^2;
end;
s2 = s2/(n-1);
end

%СТАНДАРТНОЕ ОТКЛОНЕНИЕ
function [s] = stand_deviation(s2)
s = sqrt(s2);
end

%КОЭФФИЦИЕНТ ВАРИАЦИИ
function [v] = coeff_variation(s, k)
v = s/k;
end

%НАЧАЛЬНЫЙ МОМЕНТ 
function [a] = starting_moment(x, l, n)
a = 0;
for i = 1:1:n
    a = a + x(i)^l;
end
a = 1/n*a;
end

%ЦЕНТРАЛЬНЫЙ МОМЕНТ
function [b] = central_moment(x, l, n)
b = 0;
for i = 1:1:n
    b = b + (x(i) - arif_mean(x, n))^l;
end
b = 1/n*b;
end

%ОЦЕНКА КОЭФФИЦИЕНТА АСИММЕТРИИ
function [Sk] = koef_asimm(x, n)
Sk = central_moment(x, 3, n)/(central_moment(x, 2, n))^(3/2);
end

%ОЦЕНКА ЭКСЦЕССА
function [Ex] = exscess(x, n)
Ex =  central_moment(x, 4, n)/central_moment(x, 2, n)^2 - 3;
end