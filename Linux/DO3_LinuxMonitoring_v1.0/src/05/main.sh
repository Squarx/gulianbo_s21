#!/bin/bash
export LC_CTYPE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
FILE=../func.sh
chmod +rx $FILE 2>/dev/null
if [ ! -f $FILE ]; then
    echo Ошибка: файл для заупска функций не существует: $FILE
    exit
fi
source $FILE

if [ $#  \> 1 ] || [ $#  == 0 ] ; then
    echo "Script works with 1 arg"
else 
    if [ ! ${1: -1} == "/" ]; then
        echo "not end /"
    elif  [ ! -d $1 ]; then
        echo "It is not a directory"
    else
    start=$(date +%s.%N) 
    printer5 "$1"
    dur=$(echo "$(date +%s.%N) - $start" | bc)
    printf "Script execution time (in seconds) = %.6f\n" $dur
    fi
fi


