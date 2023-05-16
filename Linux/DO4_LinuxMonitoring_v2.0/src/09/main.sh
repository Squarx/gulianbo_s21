#!/bin/bash


while true; do
    my_path=/usr/share/nginx/html/test.html
    echo "cpu_usage $(mpstat 1 1 | awk '$NF ~ /[0-9.]+/' | awk '{print (100-$NF)}' | tail -1)" > $my_path
    echo "used_ram $(free | grep Mem | awk '{print $3}')" >> $my_path
    echo "used_capacity $(df  / | awk '{print $4}' | tail -1)" >> $my_path
    sleep 1
done 