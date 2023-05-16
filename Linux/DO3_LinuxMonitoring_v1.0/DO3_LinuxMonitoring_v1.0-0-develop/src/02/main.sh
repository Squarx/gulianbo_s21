#!/bin/bash
FILE=../func.sh
chmod +rx $FILE 2>/dev/null
if [ ! -f $FILE ]; then
    echo Ошибка: файл для заупска функций не существует: $FILE
    exit
elif [ $# \> 0 ]; then
    echo Ошибка: : Скрипт не принимает аргументы
    exit
fi

source $FILE
set_date
printer_3
save_file