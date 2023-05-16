#!/bin/bash
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White


# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White


NC='\033[0m' # No Color
# 1 - white, 2 - red, 3 - green, 4 - blue, 5 – purple, 6 - black)

function set_parameters {
    parameter=$(cat parameters.conf | grep $1)
    clear=${parameter##*"="}
    if [[ $clear =~ [0-9] ]]; then
        if [[ $clear != [1-6] ]]; then
            echo "0"
        else
            echo $clear
        fi
    else
        echo "0"
    fi

}

function fc(){
    ret_color=$NC
    if [[ "$1" =~ [1-6] ]]; then
        case "$1" in
        "1") ret_color=$White;;
        "2") ret_color=$Red;;
        "3") ret_color=$Green;;
        "4") ret_color=$Blue;;
        "5") ret_color=$Purple;;
        "6") ret_color=$Black;;
        esac
    fi
    echo  $ret_color
}

function bc_num(){
    ret_color="0"
    if [[ "$1" =~ [1-6] ]]; then
        case "$1" in
        "1") ret_color="47";;
        "2") ret_color="41";;
        "3") ret_color="42";;
        "4") ret_color="44";;
        "5") ret_color="45";;
        "6") ret_color="40";;
        esac
    else ret_color="0";
    fi
    echo  $ret_color
}

function fc_num(){
    ret_color="0"
    if [[ "$1" =~ [1-6] ]]; then 
        case "$1" in
        "1") ret_color="37";;
        "2") ret_color="31";;
        "3") ret_color="32";;
        "4") ret_color="34";;
        "5") ret_color="35";;
        "6") ret_color="30";;
        esac
    else 
        ret_color="0";
        # echo $ret_color
    fi
    echo  $ret_color

}

function set_date() {
zone="Europe/Moscow"
if [ $# == 1 ]; then
    zone="$1"
fi
sudo timedatectl set-timezone "$zone" 
}


function save_file() {
    echo -n "Save result in file (Y/N)? "
    read input
   case "$input" in
    "Y" | "y")
    printer_3 >> $(date +"%d_%m_%y_%H_%M_%S").status
    ;;
    *)
    echo "Not saving"
    ;;
esac 
}


function printer_3() {
    # echo $#
    timezone=$(timedatectl | grep Time | sed 's/^[[:space:]]*//' | awk '{print $3 " UTC "  substr($5, 0, 1) substr($5, 3, 1) }')
    host=$(hostname)
    user=($USER)
    os=$(hostnamectl | grep 'Operating System: ' | sed 's/Operating System: //')
    date=$(date '+%d %b %Y %T')
    uptime=$(uptime --pretty)
    uptime_sec=$(awk '{print $1}' /proc/uptime)
    ip=$(ip -4 a | grep "inet " | sed 's/\// /' | sed -n '2p' | awk '{print $2}')
    mask=$(ifconfig | grep inet | awk '{print $4}' | sed -n '1p')
    gateway=$(ip r | grep default | awk '{print $3}')
    ram_total=$(free | grep Mem | awk '{printf "%.3f GB", $2 / 1048576}')
    ram_used=$(free | grep Mem | awk '{printf "%.3f GB", $3 / 1048576}')
    ram_free=$(free | grep Mem | awk '{printf "%.3f GB", $4 / 1048576}')
    space_root=$(df -l |  grep  "\/$" | awk '{printf "%.2f MB", $2 / 1024}')
    space_root_used=$(df -l |  grep  "\/$" | awk '{printf "%.2f MB", $3 / 1024}')
    space_root_free=$(df -l |  grep  "\/$" | awk '{printf "%.2f MB", $4 / 1024}')
# Параметр 1 - это фон названий значений (HOSTNAME, TIMEZONE, USER и т.д.)
# Параметр 2 - это цвет шрифта названий значений (HOSTNAME, TIMEZONE, USER и т.д.)
# Параметр 3 - это фон значений (после знака '=')
# Параметр 4 - это цвет шрифта значений (после знака '=')
    printf "${1}HOSTNAME$3= $2%s$3\n" "$host"
    printf "${1}TIMEZONE${3} = $2%s${3}\n" "$timezone"
    printf "${1}USER${3}= $2%s${3}\n" "$user"
    printf "${1}OS${3}= $2%s${3}\n" "$os"
    printf "${1}DATE${3} = $2%s${3}\n" "$date"
    printf "${1}UPTIME${3} = $2%s${3}\n" "$uptime"
    printf "${1}UPTIME_SEC${3} = $2%s${3}\n" "up $uptime_sec sec"
    printf "${1}IP${3} = $2%s${3}\n" "$ip"
    printf "${1}MASK${3} = $2%s${3}\n" "$mask"
    printf "${1}GATEWAY${3} = $2%s${3}\n" "$gateway"
    printf "${1}RAM_TOTAL${3} = $2%s${3}\n" "$ram_total"
    printf "${1}RAM_USED${3} = $2%s${3}\n" "$ram_used"
    printf "${1}RAM_FREE${3} = $2%s${3}\n" "$ram_free"
    printf "${1}SPACE_ROOT${3} = $2%s${3}\n" "$space_root"
    printf "${1}SPACE_ROOT_USED${3} = $2%s${3}\n" "$space_root_used"
    printf "${1}SPACE_ROOT_FREE${3} = ${2}%s${3}\n" "$space_root_free"
}


function printer5() {
echo "Total number of folders (including all nested ones) = $( find $1* -type d 2>/dev/null | wc -l)"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
du -h $1 2>/dev/null | sort -h -r | head -6 | tail -n 5 | awk 'BEGIN {i=1} {print i" - " $2", "$1} {i++}'
echo Total number of files = $(find $1* -type f 2>/dev/null | wc -l)
echo Number of:
echo "Configuration files (with the .conf extension) =" $(find $1 2>/dev/null -type f -name "*.conf" | wc -l)
echo "Text files = "$(find $1 2>/dev/null -type f -name "*.txt" | wc -l)
echo "Executable files = " $(find $1 -type f -executable  2>/dev/null | wc -l)
echo "Log files (with the extension .log) = " $(find $1 2>/dev/null -type f -name "*.log" | wc -l)
echo "Archive files = " $(find $1 2>/dev/null -type f -name "*.7z" -oname ".zip" -oname "*.rar" -oname "*.tar" | wc -l)
echo "Symbolic links = "$(find $1 2>/dev/null -type l | wc -l)
echo "TOP 10 files of maximum size arranged in descending order (path, size and type): "
for (( i=1; i < 11; i++ ))
do 
    tmp=$(find $1 -type f -exec du -h {} + 2>/dev/null | sort -hr | cat -n | sed -n "${i}p")
    if [ "$tmp" == "" ]; then
        break;
    fi
    ext=$( echo "$tmp" |  awk '{print $3}') 
    b="${ext##*.}"
    echo $i - $(echo "$tmp" |  awk '{print $3 ", " $2}'), $b
done
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"

find $1 -type f -executable -exec du -h {} + 2>/dev/null | sort -hr | head -10 | awk 'BEGIN {i=1} { 
    cmd = "shasum -a 1 " $2; 
    cmd | getline shasum; 
    close(cmd);
    split(shasum, arr, " ");  
    print i" - " $2 ", " $1 ", "  arr[1];
    i++ 
}'
}

function generaror(){
for (( i=1; i < 10; i++))
do
    gcc 1.c -o a$i.out
done
}


function get_color() {
        ret_color=""
        case "$1" in
        "1") ret_color="(white)";;
        "2") ret_color="(red)";;
        "3") ret_color="(green)";;
        "4") ret_color="(blue)";;
        "5") ret_color="(purple)";;
        "6") ret_color="(black)";;
        esac
        echo  $ret_color
}


function valid_input(){
for i in $@
do
    if [[ $i =~ ^[0-9]{1}$ ]]; then
        # echo $i
        if [[ ! $i =~ [1-6] ]]; then
            echo "Параметр должен содержать цифры 1-6"
            exit
        fi
    else
        if [[ $i =~ [+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$ ]]; then
            echo "Параметр должен содержать цифры 1-6"
        else
            echo "Need number"
        fi
        exit
    fi
done
}

function quest3() {
if [ $# -eq 4 ]; then
        valid_input $1 $2 $3 $4
    if [ $1 -eq $2 ] || [ $3 -eq $4 ]; then
        echo Paramets must be different \(Par1 == Par2  or Par3 == Par4\)
    else
        valid_input $1 $2 $3 $4
        color_info="\033[$(bc_num $1);$(fc_num $2)m"
        color_values="\033[$(bc_num $3);$(fc_num $4)m"
        end="\033[0m"
        printer_3 "$color_info" "$color_values" "$end"
    fi
else
    echo "Need 4 parametr"
fi
}

function print_colors() {
    error=""
    if [ "$5" != "" ]; then
        error="(default)"
    fi
# echo $1 $2 $3 $4
echo ""
echo "Column 1 background = $1 $error $(get_color $1)"
echo "Column 1 font color = $2 $error $(get_color $2)"
echo "Column 2 background = $3 $error $(get_color $3)"
echo "Column 2 font color = $4 $error $(get_color $4)"
}
