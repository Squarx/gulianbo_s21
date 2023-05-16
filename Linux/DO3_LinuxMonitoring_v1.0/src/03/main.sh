#!/bin/bash
FILE=../func.sh
chmod +rx $FILE 2>/dev/null
if [ ! -f $FILE ]; then
    echo Ошибка: файл для заупска функций не существует: $FILE
    exit
elif [ $# \> 4 ];then
    echo Ошибка: скрипт принимает 4 аргумента
    exit
fi
source $FILE
quest3 $1 $2 $3 $4
