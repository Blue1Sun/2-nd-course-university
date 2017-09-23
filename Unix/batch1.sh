#!/bin/bash
if [ "$1" = "-help" ] # вызов справки
then
echo -e "This program prints text in files\nArguments = name of files\nFiles must exist!"
exit
fi
echo "You gave me $# files"
if [ $# -eq 0 ] # если аргументов нет
then
echo "NO ARGUMENTS! Please, if you need help, type Цhelp as argument"
else
for file
in $*
do
if test -r $file # если файл существует и доступен дл€ чтени€
then
echo -e "\nprinting $file..."
more "$file"
else # если файл не существует или недоступен дл€ чтени€
echo -e "\nERROR! NO SUCH FILE (name = $file)!"
fi
done
fi