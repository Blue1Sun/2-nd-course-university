D = eye(100,100);
C1 = logical(D);
for i=1:1:100
    for j=1:1:100
        k=101-i;
        l=101-j;
        C2(i,j) = C1(k,l);
    end
end
for i=1:1:25
    for j=1:1:25
        k=i+4;
        l=j+4;
        C3(i,j)=C1(k,l);
    end
end
for i=1:1:50
    for j=1:1:50
        k=i+5;
        l=j+5;
        C4(i,j)=C1(k,l);
    end
end
subplot(2,2,1);
title('1st image');
ylabel('y label')
xlabel('x label')
xlim([0 100])
ylim([0 100])
hold on
imshow(C1)

subplot(2,2,2);
title('2nd image');
ylabel('y label')
xlabel('x label')
xlim([0 100])
ylim([0 100])
hold on
imshow(C2)

subplot(2,2,3);
title('3rd image');
ylabel('y label')
xlabel('x label')
xlim([0 100])
ylim([0 100])
hold on
imshow(C3)

subplot(2,2,4);
title('4th image');
ylabel('y label')
xlabel('x label')
xlim([0 100])
ylim([0 100])
hold on
imshow(C4)