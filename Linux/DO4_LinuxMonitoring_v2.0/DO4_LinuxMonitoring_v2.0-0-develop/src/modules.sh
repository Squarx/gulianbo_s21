#!/bin/bash

function checkPath() {
    if [ ! -d "$1" ]; then
    echo "$1 doesn't exist or isn't a directory."
    exit 1
    fi
    if [ ! -w "$1" ]; then
    echo "Can't write to $1. Check permissions."
    exit 1
    fi
}

function checkCountDirs() {
    if [[ ! "$1" =~ ^[1-9]([0-9]?)+$ ]]; then
    echo "Count dirs must be > 0 (got $1)"
    exit
fi
}
function checkCountFiles() {
    if [[ ! "$1" =~ ^[1-9]([0-9]?)+$ ]]; then
    echo "Count files must be > 0 (got $1)"
    exit
fi
}

function checkDirLetters() {
    if [[ (-z "$1") || (! $1 =~ ^[a-zA-Z]{1,7}$) ]]; then
        echo "Number of letter for creating dirs must be < 8 (got $1)"
        exit 1 
    fi
}

function checkFileLetters() {
        if [[ (-z "$1") || (! $1 =~ ^[a-zA-Z]{1,7}$) ]]; then
        echo "Invalid filename(got $1)"
        exit 1 
    fi
}

function checkExtLetters() {
        if [[ -z "$1" || (! $1 =~ ^[a-zA-Z]{1,3}$) ]]; then
        echo "Invalid file extention (got $1)"
        exit 1 
    fi
}

function checkSizeKb() {
if [[ ! "$1" =~ ^[1-9]([0-9]{1,2})?kb$  ]]; then
    echo "Invalid file size format $1"
    exit 1
fi
local size="${1%kb}"
# Проверяем, что число больше 0 и не превышает 100
if (( size < 1 || size > 100 )); then
  echo "Error: invalid size range $size"
  exit 1
fi
}

function checkSizeMb() {
if [[ ! "$1" =~ ^[1-9]([0-9]{1,2})?Mb$  ]]; then
    echo "Invalid file size format $1"
    exit 1
fi
local size="${1%Mb}"
# Проверяем, что число больше 0 и не превышает 100
if (( size < 1 || size > 100 )); then
  echo "Error: invalid size range $size"
  exit 1
fi
}



function multichar() {
    char=$1
    count=$2
    result=""
        for (( a = 0; a < count; a++ ))
    do
        result+=$char
    done
    echo "$result"
}

function splitCharsFile() {
file_chars=$1
if [[ "$file_chars" =~ \. ]]; then
    file_name=$(echo "$file_chars" | cut -d '.' -f 1)
    file_ext=$(echo "$file_chars" | cut -d '.' -f 2)
else
    file_name=$(echo "$file_chars" | cut -d '.' -f 1)
fi
    echo "$file_name $file_ext"
}

function checkSpace {
    space=$(df / | awk 'NR==2 {print int($4/1024/1024)}')
    [[ $space -lt 1 ]] && {
        echo "################################################################################################"
        echo "#                                                                                              #"
        echo "#                                                                                              #"
        echo "#           Warning: The space of the '/' directory has just became less than 1GB              #"
        echo "#                                                                                              #"
        echo "#                                                                                              #"
        echo "################################################################################################"
    } && endExecTime && printExecutionTime&& exit
}


function pathcheck() {
        if [ ! "${1: -1}" == "/" ]; then
       echo "$1/"
    else
    echo "$1"  
    fi
}


# $1 - dirpath (добаляется к name) 
# $2 - file_name (алфавит букв)
# $3 - max (количество)
# $4 - "yes" or "" - (добавить "_DDMMYY" к названиям)
# $5 - 3 min кол во символов для имени
function generator_names() {
    dirPath=$1
    file_name=$2
    max=$3
    min=$5
    addDay=$4
    # echo "HERERERRERERRE |$1| |$2| |$3| |$4|"
    len=${#file_name}
    offset=0
    cnt=0
    Day="_$(date +%d%m)$(date | awk '{print $NF}' | awk '{print substr($0,3,2)}')"
    if [ -z "$addDay" ]; then
        Day=""
    fi
    if [[ (-n "$dirPath") && ("${dirPath: -1}" != "/") ]]; then
        dirPath+="/"
    fi
    daylen=${#Day}
    read -r -a array <<< "$(echo $file_name | sed 's/\(.\)/\1 /g')"

    for (( index = 0; index < len; index++ ))
    do
        if [ $index -eq $offset ]; then

             for (( a = 0; a < 256 - (len+daylen); a++ )) #256 - (( $len+$daylen ))
             do
                name=""
                name="$name$(multichar "${array[index]}" $a)" # умножение текущей буквы на "а" раз 
                name=${file_name:0:offset}$name${file_name:offset:len}
                if [[ (${#name} -gt min)  || ( -z "$Day") ]]; then
                    name="$name$Day"
                    name="$dirPath$name"
                    echo "$name"
                    cnt=$(( cnt + 1 ))
                    # generator_ext $name $file_ext
                fi
             done
            offset=$(( offset + 1 ))
        fi
    done
}

function makeLog {
    time=$(date +"%T")
    day=$(date | awk '{print $NF}')"-"$(date +%m)"-"$(date +%d)
    path=$1
    sudo echo "$path $day $time $2" >> file.log
}

function startCalculateTime {
    StartTimeH=$(date +"%T")
    StartDateH=$(date | awk '{print $NF}')"-"$(date +%m)"-"$(date +%d)
    start_sub=$(date +%s.%N)
}

function endExecTime {
    EndTimeH=$(date +"%T")
    EndDateH=$(date | awk '{print $NF}')"-"$(date +%m)"-"$(date +%d)
    end_sub=$(date +%s.%N)
}

function printExecutionTime {
    runtime_sub=$( echo "$end_sub - $start_sub" | bc -l )
    echo "Script start time $StartDateH $StartTimeH"
    echo "Script execution time (in seconds) = ${runtime_sub} with ${cnt_all_dirs} folders and ${cnt_all_files} files"
    echo "Script end time $EndDateH $EndTimeH"
}
