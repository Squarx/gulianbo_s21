#!/bin/bash

if [[ $# -ne 0 ]]
then
    echo "Input error! Run the script without parameters"
else
    goaccess /home/g/DO4_LinuxMonitoring_v2.0-0/src/04/*.log --log-format=COMBINED -o /home/g/DO4_LinuxMonitoring_v2.0-0/src/06/output.html
fi


# потом с локальной машины выполняю эту команду и переношу сформированный html отчет с виртуалки на локальную машину
#scp festusst@localhost:/home/festusst/src/06/output.html /home/shmupella/Desktop/Coding/projects/DO4_LinuxMonitoring_v2.0-0/src/06