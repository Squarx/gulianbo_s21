#!/bin/bash

function quest4() {
FILE=../func.sh
chmod +rx $FILE 2>/dev/null
if [ ! -f $FILE ]; then
    echo Ошибка: файл для заупска функций не существует: $FILE
    exit
elif [ $# \> 0 ];then
    echo Ошибка: скрипт не принимает  аргументов \( получено $#\)
    exit
fi

source $FILE

b1=$(set_parameters column1_background)
c1=$(set_parameters column1_font_color)
b2=$(set_parameters column2_background)
c2=$(set_parameters column2_font_color)
err=""
if [ $b1 -eq $c1 ] || [ $b2 -eq $c2 ] || [ $b2 -eq 0 ] || [ $b2 -eq 0 ] || [ $c1 -eq 0 ] || [ $c2 -eq 0 ]; then
    b1=1
    c1=2
    b2=3
    c2=4
    err="1"
fi
# echo $b1 $c1 $b2 $c2
color_info="\033[$(bc_num $b1);$(fc_num $c1)m"
color_values="\033[$(bc_num $b2);$(fc_num $c2)m"
end="\033[0;0m"
printer_3  $color_info  $color_values $end
print_colors $b1 $c1 $b2 $c2 $err
}

quest4 $*

