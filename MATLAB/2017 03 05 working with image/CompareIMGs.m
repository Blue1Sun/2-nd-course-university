%I = imread('bf3.jpg');
%corr = CompareIMGs(I)
function Corr = CompareIMGs(Img) 
%Img в новый файл, с параметром качество
imwrite(Img, 'Img75.jpg', 'quality', 75); 
I1 = imread('Img75.jpg'); 
imwrite(Img, 'Img50.jpg', 'quality', 50); 
I2 = imread('Img50.jpg'); 
imwrite(Img, 'Img25.jpg', 'quality', 1); 
I3 = imread('Img25.jpg'); 

%сравнение
Corr = []; 
%с 75
corr = corr2(Img(:), I1(:)); 
Corr = [Corr corr]; 
%с 50
corr = corr2(Img(:), I2(:)); 
Corr = [Corr corr]; 
%с 1
corr = corr2(Img(:), I3(:)); 
Corr = [Corr corr]; 

subplot(2,2,1), imshow(Img), title('100') %исходник
subplot(2,2,2), imshow(I1), title('75') %75
subplot(2,2,3), imshow(I2), title('50') %50
subplot(2,2,4), imshow(I3), title('1') %1
end