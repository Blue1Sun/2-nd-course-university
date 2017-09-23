function my_func( x1, x2, h )
for x = x1:h:x2
    if x<=0
        y = sqrt(1+(x^2)/(1+x^2));
    end
    if x>0
        y = 2*abs(cos(x));
    end
    disp([x,y])
end
end

