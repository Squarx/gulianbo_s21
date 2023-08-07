#!/bin/bash
reg_num="^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$"
if [ $# == 1 ]; then
    if [[ ! $1 =~ $reg_num ]]; then
        echo $1;
    fi
elif [ $# \> 1 ]; then
    echo More 1 arg;
else 
    echo "Yoy schould write 1 Arg (got 0)";
fi
