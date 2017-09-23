%I = imread('bf3.jpg');
%corr = greyLevel(I);
function [ bw ] = greyLevel( I3 )
level = graythresh(I3); %порог дл€ преобразовани€ изображени€ в двоичный
bw = im2bw(I3, level); %преобразование

%binary version
subplot(2,1,1);
imshow(bw);

%The bwlabel function labels all
%the components in the binary image bw and returns the number of components it finds
%in the image in the output value, numObjects.
[labeled, numObjects] = bwlabel(bw, 4);
fprintf('%d - numObjects1\n',numObjects); %количество объектов

 J = imcomplement(I3);

level = graythresh(J);%порог дл€ преобразовани€ изображени€ в двоичный
bw2 = im2bw(J, level);%преобразование

%binary version
subplot(2,1,2);
imshow(bw2);

%The bwlabel function labels all
%the components in the binary image bw and returns the number of components it finds
%in the image in the output value, numObjects.
[labeled, numObjects] = bwlabel(bw2, 4);
fprintf('%d\n - numObjects2',numObjects); %количество объектов
end