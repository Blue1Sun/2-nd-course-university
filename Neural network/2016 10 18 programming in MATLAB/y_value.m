function [ y ] = y_value( x )
y = sqrt(sh(sqrt(2*pi.*x)));
end
function [ t ] = sh( x )
t = (exp(x)-exp(-x))/2;
end
