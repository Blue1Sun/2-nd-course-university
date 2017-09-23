Inew=imread('bf1.jpg');
subplot(2,3,1)
imshow(Inew);
subplot(2,3,2)
I1=imrotate(Inew,35,'bicubic');
imshow(I1)
for i=1:1:300
    for j=1:1:299
        if Inew(i,j)>100
            special(i,j,:)=255;
        end
        if Inew(i,j)<100
            special(i,j,:)=0;
        end
    end
end
subplot(2,3,3)
imshow(special)
Ia=imadjust(Inew,[0 1],[0.2 0.8]);
subplot(2,3,4)
imshow(Ia)
subplot(2,3,5)
h = fspecial('laplacian',.5);
I2 = imfilter(Inew, h, 'replicate');
imshow(I2)
subplot(2,3,6)
h = fspecial('average',3);
I2 = imfilter(Inew, h, 'replicate');
imshow(I2)