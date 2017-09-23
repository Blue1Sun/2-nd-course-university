#!/bin/bash
echo "Enter file_name in which you want to add lines"
read fname
echo "Enter number_of_lines you want to add to your file"
read nl
temp=$(($nl+0)) # временная переменная для проверки на число
if [ "$nl" = "$temp" -a "$fname" != "" ] # если nl - число, а название файла дано(любое непустое)
then
if [ "$nl" -gt 0 ] #если nl > 0
then
echo "file = $fname --- number of lines = $nl"
i=0 #переменная для цикла
until [ "$i" = "$nl" ] # пока не добавим нужное число строк
do
i=`expr $i + 1`
echo "Enter $i'st line"
read line
echo "$line" >> $fname
done
else
echo "LINES <= ZERO" #nl <=0 #nl <=0
fi
else
echo "WRONG ARGUMENTS" # nl - не число или название файла пусто
fi