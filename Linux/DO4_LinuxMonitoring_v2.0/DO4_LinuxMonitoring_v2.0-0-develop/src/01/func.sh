#!/bin/bash
. ../modules.sh


function checks() {
if [ "$#" -ne 6 ]; then
    echo "Script using with 6 args"
    echo "Usage: $0 <path> <depth> <dir_chars> <file_count> <file_chars> <file_size_kb>"
    exit 1
fi
# Переменные для параметров
path="$1"
depth="$2"
dir_chars="$3"
file_count="$4"
file_chars="$5"
file_size_kb="$6"
result=$(splitCharsFile "$file_chars")
file_name=$(echo "$result" | awk '{print $1}')
file_ext=$(echo "$result" | awk '{print $2}')
# Проверяем, что путь существует и можно записывать в него
checkPath "$path"
checkCountDirs "$depth"
checkCountFiles "$file_count"
#Количество букв для папок < 8
checkDirLetters "$dir_chars"
#Название файла есть (file_name = ".az")
checkFileLetters "$file_name"
#Количество букв для  расширения < 3
checkExtLetters "$file_ext"
#
checkSizeKb "$file_size_kb"
}



function optimizedGeneration() {
    startCalculateTime
    working_path=$1 # добавляет к пути  в конец /
    dir_count=$2
    dir_chars="$3"
    file_count=$4
    file_chars="$5"
    file_size_kb="$6"
    cnt_dirs=0
    cnt_files=0
    # prirnter "$working_path" $dir_count $dir_chars $file_count $file_chars $file_size_kb

    result=$(splitCharsFile "$file_chars")
    file_name=$(echo "$result" | awk '{print $1}')
    file_ext=$(echo "$result" | awk '{print $2}')
    mapfile -t arr_dirs < <(generator_names "$working_path" "$dir_chars" "$dir_count" "yes" 0)
    mapfile -t arr_names < <(generator_names "" "$file_name" "" "yes" 0) #cоздание массива ??? PATH
    mapfile -t arr_ext < <(generator_names "" "$file_ext" "" "" 0) #cоздание массива
    cnt_all_dirs=0
    cnt_all_files=0
    # echo "Script execution time (in seconds) = ${runtime_sub} with ${cnt_all_dirs} folders and ${cnt_all_files} files"
for curr_dir in "${arr_dirs[@]}"
do
    cnt_files=0
    if [ ! -d  "$curr_dir" ]; then
        mkdir "$curr_dir"
        # echo "DIRNAME $curr_dir"
        cnt_dirs=$(( $cnt_dirs + 1 ))
        cnt_all_dirs=$(( $cnt_all_dirs + 1 ))
    fi

    for curr_name in "${arr_names[@]}"
    do
        for curr_ext in "${arr_ext[@]}"
        do  
            nameFile=""
            nameFile="$curr_name.$curr_ext"

            if [[ (${#nameFile} -lt 256) && (! -f "$nameFile") ]]; then
                # echo "FILE created $cnt_dirs |$cnt_files|"
                cnt_files=$(( cnt_files + 1 ))
                cnt_all_files=$(( cnt_all_files + 1 ))
                sudo fallocate -l "$file_size_kb" "$curr_dir/$nameFile"
                makeLog "$curr_dir/$nameFile" "$file_size_kb" 
                checkSpace
                if [[ cnt_files -ge file_count ]]; then
                break 2
                fi
            fi 
        if [[ cnt_files -ge file_count ]]; then  
            break 1
        fi
        done
    done
    if [[ cnt_dirs -ge dir_count ]]; then
        break 1
    fi

done
endExecTime
printExecutionTime
}

function logger() {
    for i in "${arr_dirs[@]}"
    do
    echo "$i"
    done > dirs.log
    for i in "${arr_names[@]}"
    do
    echo "$i"
    done > Names.log
        for i in "${arr_ext[@]}"
    do
    echo "$i"
    done > Ext.log
}

function prirnter() {
echo Len of file_name ${#file_name}
echo Len of file_ext ${#file_ext}
printf '%s' "
path = $path
depth = $depth
dir_chars = $dir_chars 
file_count  = $file_count  
file_chars = $file_chars 
file_size_kb = $file_size_kb
file_name = $file_name
file_ext = $file_ext
"
}





