#!/bin/bash

function valid() {
  if [ "$#" -ne 1 ]; then
    echo "Script usage requires exactly 1 argument"
    echo "Usage: $0 <NUM 1-3>"
    exit 1
  fi
  if ! [[ "$1" =~ ^[1-3]$ ]]; then
    echo "Invalid number format: $1"
    echo "Usage: $0 <NUM 1-3>"
    exit 1
  fi
}


function CleanByLog() {
    # while IFS= read -r line; do
    #     array+=("${line%?}")
    # done < ../02/file.log
    # while IFS= read -r line; do
    # array+=("$(echo "$line" | cut -d ' ' -f1)")
    # done < ../02/file.log

    while IFS= read -r line; do
    line="$(echo "$line" | cut -d ' ' -f1)"
    # echo "$line"
    sudo rm -rf "$(dirname "$line")" 2> /dev/null
    sudo rm -rf "$line" 2> /dev/null
    done < ../02/file.log
}

function printDateData() {
    echo "dayStart = $dayStart"
    echo "dayEnd = $dayEnd"
    echo "timeStart = $timeStart"
    echo "timeEnd = $timeEnd"
    echo "left = $timeStartUnix"
    echo "right = $timeEndUnix"
}

function safeDelete() {
  local currDir=$1
  echo "Found directory $currDir"
  echo "Would you like to delete [Y/n]"
  read -ru 0 input
  case "$input" in
    "Y" | "y")
    echo "rm -rf $currDir"
    ;;
    *)
    echo "Not deleting"
    ;;
  esac 
}

function forceDelete() {
  sudo rm -rf "$1" 2> /dev/null
}
function logDir() {
  echo "$1" >> deletedDirs.log
}

function cleanByDate() {
regular="^([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})$"
    echo
        read -rp "Enter START time of range in format of YYYY-MM-DD HH:MM:SS
        " startTimeRange
        read -rp "Enter END time of range in format of YYYY-MM-DD HH:MM:SS
        " endTimeRange

        if [[ ! ($startTimeRange =~ $regular) ||  ! ($endTimeRange =~ $regular) ]];then
            echo "Forbidden format date"
            echo "Got start = $startTimeRange"
            echo "Got end = $endTimeRange"
            exit 1
        fi
        # startTimeRange="2023-04-15 07:18:40"
        # endTimeRange="2023-04-15 07:22:40"

    regular="^.*[a-zA-Z]*_([0-9]{2})([0-9]{2})([0-9]{2}).*$"

    # sudo find / -type d 2> /dev/null | grep -v -e "bin" -e "sbin" -e "etc" -e "sys" -e "proc" -e "dev" -e "snap" >> directories.tmp
    dayStart=$(echo "$startTimeRange" | awk '{print $1}')
    dayEnd=$(echo "$endTimeRange" | awk '{print $1}')
    timeStart=$(echo "$startTimeRange" | awk '{print $2}')
    timeEnd=$(echo "$endTimeRange" | awk '{print $2}')
    timeStartUnix=$(date -d "$dayStart $timeStart" +%s)
    timeEndUnix=$(date -d "$dayEnd $timeEnd" +%s)
    # printDateData
    while read -r currDir; do
        dirTime=$(stat -c %y "$currDir" 2> /dev/null  | awk '{print $2}' | awk -F"." '{print $1}')
        dirDay=$(stat -c %y "$currDir" 2> /dev/null  | awk '{print $1}')
        dirUnixTime=$(date -d "$dirDay $dirTime" +%s)
        [[ "$currDir" =~ $regular ]] \
        && [[ $timeStartUnix -le $dirUnixTime ]] && [[ $timeEndUnix -ge $dirUnixTime ]] \
        && forceDelete "$currDir" && logDir "$currDir"
    done  < <(sudo find / -type d -writable 2> /dev/null | grep -vE '/(bin|sbin|sys|proc|dev|snap)/?')
}

function cleanByRegex() {
  # regular="^.*[a-zA-Z]*_([0-9]{2})([0-9]{2})([0-9]{2}).*$"
  regular="^.*[a-zA-Z]*_([0-9]{2})([0-9]{2})([0-9]{2})$"
      while read -r currDir; do
        [[ "$currDir" =~ $regular ]] \
        && forceDelete "$currDir" && logDir "$currDir"
    done  < <(sudo find / -type d -writable 2> /dev/null | grep -vE '/(bin|sbin|sys|proc|dev|snap)/?')

}

function task3() {
if [ "$1" -eq 1 ]; then
    array=()
    CleanByLog
    # printArray
elif [ "$1" -eq 2 ]; then
    cleanByDate
elif [ "$1" -eq 3 ]; then
    cleanByRegex
else
    echo "I don't understand"
fi
}