#!/bin/bash
echo "Enter file_name in which you want to add lines"
read fname
echo "Enter number_of_lines you want to add to your file"
read nl
temp=$(($nl+0)) # ��������� ���������� ��� �������� �� �����
if [ "$nl" = "$temp" -a "$fname" != "" ] # ���� nl - �����, � �������� ����� ����(����� ��������)
then
if [ "$nl" -gt 0 ] #���� nl > 0
then
echo "file = $fname --- number of lines = $nl"
i=0 #���������� ��� �����
until [ "$i" = "$nl" ] # ���� �� ������� ������ ����� �����
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
echo "WRONG ARGUMENTS" # nl - �� ����� ��� �������� ����� �����
fi