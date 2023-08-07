#!/bin/bash
path=$(pwd)
day=$(echo $1 | awk '{printf "%02d", $0}')
for (( i = 0; i <= $2; ++i )) 
do
    ex=$(echo $i | awk '{printf "ex%02d", $0}')
    dir="$path"/$ex
    if [ ! -d $dir ]; then
        mkdir "$dir"
        touch $dir/"day"$day"_"$ex.sql
    fi
done