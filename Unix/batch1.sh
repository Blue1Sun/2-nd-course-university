#!/bin/bash
if [ "$1" = "-help" ] # ����� �������
then
echo -e "This program prints text in files\nArguments = name of files\nFiles must exist!"
exit
fi
echo "You gave me $# files"
if [ $# -eq 0 ] # ���� ���������� ���
then
echo "NO ARGUMENTS! Please, if you need help, type �help as argument"
else
for file
in $*
do
if test -r $file # ���� ���� ���������� � �������� ��� ������
then
echo -e "\nprinting $file..."
more "$file"
else # ���� ���� �� ���������� ��� ���������� ��� ������
echo -e "\nERROR! NO SUCH FILE (name = $file)!"
fi
done
fi