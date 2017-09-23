D = eye(100,100);
%формирование C1
C1 = logical(D);
%формирование Ќ
BI1 = [1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 1 0
1 1 1 1 1 0
1 0 0 0 1 0
1 0 0 0 1 0];
%формирование ј
BI2 = [0 1 1 1 1 0
0 1 0 0 1 0
0 1 0 0 1 0
0 1 1 1 1 0
0 1 0 0 1 0
0 1 0 0 1 0];
%формирование “
BI3 = [1 1 1 1 1 1
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0];
%формирование A
BI4 = BI2;
%формирование Ћ
BI5 = [0 0 1 1 0 0
0 1 0 0 1 0
1 0 0 0 0 1
1 0 0 0 0 1
1 0 0 0 0 1
1 0 0 0 0 1];
%формирование »
BI6 = [0 1 0 0 0 1
0 1 0 0 1 1
0 1 0 1 0 1
0 1 0 1 0 1
0 1 1 0 0 1
0 1 0 0 0 1];
%формирование я
BI7 = [0 1 1 1 1 1
0 1 0 0 0 1
0 1 1 1 1 1
0 0 0 1 0 1
0 0 1 0 0 1
0 1 0 0 0 1];
%вписывание букв 
C1(11:16,2:7) = BI1;
C1(11:16,8:13) = BI2;
C1(11:16,14:19) = BI3;
C1(11:16,20:25) = BI4;
C1(11:16,26:31) = BI5;
C1(11:16,32:37) = BI6;
C1(11:16,38:43) = BI7;

%формирование C2
for i=1:1:100
    for j=1:1:100
        k=101-i;
        l=101-j;
        C2(i,j)=C1(k,l);
    end
end
%формирование C3
for i=1:1:25
    for j=1:1:25
        k = i*4;
        l = j*4;
        C3(i,j)=C1(k,l);
    end
end
%формирование C4
for i = 1:1:50
    for j = 1:1:50
        k = i*2;
        l = j*2;
        C4(i,j) = C1(k,l);
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