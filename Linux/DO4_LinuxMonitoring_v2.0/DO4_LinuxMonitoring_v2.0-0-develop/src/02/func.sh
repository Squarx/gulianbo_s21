#!/bin/bash
. ../modules.sh

function SetVaribles() {
    dir_chars=$1
    file_chars=$2
    result=$(splitCharsFile "$file_chars")
    file_name=$(echo "$result" | awk '{print $1}')
    file_ext=$(echo "$result" | awk '{print $2}')
    file_size_mb="$3"
    CheckVars "$@"
    arr_dirs={}
    count_dirs=0
    mapfile -t arr_dirs < <(sudo find / -type d -writable 2> /dev/null | grep -vE '/(bin|sbin|sys|proc|dev|snap)/?')
    count_dirs=${#arr_dirs[@]}
    date="_$(date +%d%m)$(date | awk '{print $NF}' | awk '{print substr($0,3,2)}')"
    datelen=${#date}
    space=$(df / | awk 'NR==2 {print int($4/1024/1024)}')
}

function setRandomValues() {
    # Генерируем случайное число от 0 до (num_dirs - 1)
    random_index=$((RANDOM % count_dirs))
    random_path=${arr_dirs[random_index]}
    random_cnt_dirs=$((RANDOM % 100))
    random_cnt_files=$((RANDOM % 100))
}
printer() {
    echo "dir_chars = $dir_chars"
    echo "file_chars = $file_chars"
    echo "file_name = $file_name"
    echo "file_ext = $file_ext"
    echo "file_size_mb = $file_size_mb"
    echo "count_dirs = $count_dirs"
    echo "random_index = $random_index"
    echo "random_path = $random_path"
    echo "date = $date"
    echo "datelen = $datelen"
    echo "space  = $space"
}
function print_random() {
    echo "random_index = $random_index"
    echo "random_path = $random_path"
    echo "random_cnt_dirs = $random_cnt_dirs"
    echo "random_cnt_files = $random_cnt_files"
    echo "space  = $space"
}
function CheckVars() {
if [ "$#" -ne 3 ]; then
    echo "Script using with 3 args"
    echo "Usage: $0 <dir_chars> <file_chars> <file_size_Mb>"
    exit 1
fi
#Количество букв для папок < 8
checkDirLetters "$dir_chars"

#Название файла есть (file_name = ".az")
checkFileLetters "$file_name"

#Количество букв для  расширения < 3
checkExtLetters "$file_ext"

#
checkSizeMb "$file_size_mb"

}

function task2() {
    
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#  arr_dirs    - список директорий дступных для записи                             #
#  count_dirs  - уоличество директорий                                             #
#  random_index                                                                    #
#  random_path  - значение путя в рандомный момент времени                         #
#  dir_chars    - алфавит букв для директорий                                      #
#  file_chars                                                                      #
#  file_name                                                                       #
#  file_ext                                                                        #
#  file_size_mb                                                                    #
#  date                                                                            #
#  datelen                                                                         #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
startCalculateTime
SetVaribles "$@"
# setRandomValues
mapfile -t gen_dir_names < <(generator_names "$random_path" "$dir_chars" "" "yes" 4)
mapfile -t gen_file_names < <(generator_names "" "$file_name" "" "yes" 4) #cоздание массива ??? PATH
mapfile -t gen_ext_names < <(generator_names "" "$file_ext" "" "" 0) #cоздание массива
# printer
cnt_all_files=0
cnt_all_dirs=0
while [[ $space -gt 1 ]]
do
    cnt_created_dirs=0
    setRandomValues #random_index random_path random_cnt_dirs random_cnt_files
    # print_random
    for curr_dir in "${gen_dir_names[@]}"
    do
        cnt_created_files=0
        if [ ! -d  "$random_path/$curr_dir" ]; then
            sudo mkdir "$random_path/$curr_dir"
            # echo "DIRNAME $random_path/$curr_dir"
            # echo "Space = $space"
            cnt_created_dirs=$(( cnt_created_dirs + 1 ))
            cnt_all_dirs=$(( cnt_all_dirs + 1 ))
        fi
        for curr_name in "${gen_file_names[@]}"
        do
            for curr_ext in "${gen_ext_names[@]}"
            do
            nameFile=""
            nameFile="$curr_name.$curr_ext"            
            if [[ ${#nameFile} -gt 255 ]];then
                break 1;
            fi
            if [[ ! -f "$nameFile" ]]; then
                # echo "FILE created $cnt_created_dirs |$cnt_created_files|"
                cnt_created_files=$(( cnt_created_files + 1 ))
                cnt_all_files=$(( cnt_all_files + 1 ))
                sudo fallocate -l "$file_size_mb" "$random_path/$curr_dir/$nameFile"
                makeLog "$random_path/$curr_dir/$nameFile" "$file_size_mb"
                # echo "$random_path/$curr_dir/$nameFile" "$file_size_mb"
                # sleep 1
                # echo "CNT = $cnt_files" 
                checkSpace
            fi
            if [[ (cnt_created_files -eq random_cnt_files) || (cnt_created_files -gt random_cnt_files) ]]; then
                break 2
            fi
            done # ext
            checkSpace
            if [[ (cnt_created_files -eq random_cnt_files) || (cnt_created_files -gt random_cnt_files) ]]; then
                break 1
            fi
        done # file
        checkSpace
        if [[ (cnt_created_dirs -eq random_cnt_dirs) || (cnt_created_dirs -gt random_cnt_dirs) ]]; then
            break 1
        fi
    done # dir
    checkSpace
done # space



# echo "Count writable dirs $count_dirs"
# echo "Random path $random_path"
endExecTime
printExecutionTime
}
