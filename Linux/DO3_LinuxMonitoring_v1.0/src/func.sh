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

function converter_mask() {
    prefix_mask=$1
    byte_count=$((prefix_mask / 8))
    bit_count=$((prefix_mask % 8))
    mask=""
    for ((i=0; i<4; i++)); do
        if [ $byte_count -gt 0 ]; then
            mask+="255."
            byte_count=$((byte_count - 1))
        elif [ $bit_count -gt 0 ]; then
            mask+="$((256 - 2**(8 - bit_count)))."
            bit_count=0
        else
            mask+="0."
        fi
    done
    mask="${mask%?}"
    echo "$mask"
}

function save_file() {
    echo -n "Save result in file (Y/N)? "
    read input
   case "$input" in
    "Y" | "y")
    echo -e "$result" >> $(date +"%d_%m_%y_%H_%M_%S").status
    ;;
    *)
    echo "Not saving"
    ;;
esac 
}


function get_ram_memory() {
    free | awk  '
    BEGIN {
            col='$1';
            unit = 1024 * 1024;
            format = "%.3f GB\n";
    } 
    /Mem/ {
        printf format, $col / unit;
    }'
}

function get_space_memory() {
    free | awk  '
    BEGIN {
            col='$1';
            unit = 1024 * 1024;
            format = "%.3f GB\n";
    } 
    /Mem/ {
        printf format, $col / unit;
    }'
}

function get_space_memory() {
    df -l | grep "\/$" | awk '
     BEGIN {
            col='$1';
            unit = 1024;
            format = "%.2f MB\n";
    } 
    {
        printf format, $col / unit;
    }'
}
function printer_3() {
    # echo $#
    timezone="$(cat /etc/timezone) UTC $(date +%:::z | sed 's/0//')"
    # timezone=$(timedatectl | grep Time | sed 's/^[[:space:]]*//' | awk '{print $3 " UTC "  substr($5, 0, 1) substr($5, 3, 1) }')
    host=$(hostname)
    user=($USER)
    os=$(hostnamectl | grep 'Operating System: ' | sed 's/Operating System: //')
    date=$(date '+%d %b %Y %T')
    uptime=$(uptime --pretty)
    uptime_sec=$(awk '{print $1}' /proc/uptime)
    ip=$(ip -4 a | grep "inet " | sed 's/\// /' | sed -n '2p' | awk '{print $2}')
    mask=$(converter_mask $(ip a | grep -e "$ip" | awk '{printf "%s\n", $2}' | awk -F"/" '{print $2}'))
    gateway=$(ip r | grep default | awk '{print $3}' | head -1)
    ram_total=$(get_ram_memory 2)
    ram_used=$(get_ram_memory 3)
    ram_free=$(get_ram_memory 4)
    space_root=$(get_space_memory 2)
    space_root_used=$(get_space_memory 3)
    space_root_free=$(get_space_memory 4)
# Параметр 1 - это фон названий значений (HOSTNAME, TIMEZONE, USER и т.д.)
# Параметр 2 - это цвет шрифта названий значений (HOSTNAME, TIMEZONE, USER и т.д.)
# Параметр 3 - это фон значений (после знака '=')
# Параметр 4 - это цвет шрифта значений (после знака '=')
    result=''
    result+=$(printf "${1}HOSTNAME$3 = $2%s$3\n" "$host")
    result+='\n'
    result+=$(printf "${1}TIMEZONE${3} = $2%s${3}\n" "$timezone")
    result+='\n'
    result+=$(printf "${1}USER${3} = $2%s${3}\n" "$user")
    result+='\n'
    result+=$(printf "${1}OS${3} = $2%s${3}\n" "$os")
    result+='\n'
    result+=$(printf "${1}DATE${3} = $2%s${3}\n" "$date")
    result+='\n'
    result+=$(printf "${1}UPTIME${3} = $2%s${3}\n" "$uptime")
    result+='\n'
    result+=$(printf "${1}UPTIME_SEC${3} = $2%s${3}\n" "up $uptime_sec sec")
    result+='\n'
    result+=$(printf "${1}IP${3} = $2%s${3}\n" "$ip")
    result+='\n'
    result+=$(printf "${1}MASK${3} = $2%s${3}\n" "$mask")
    result+='\n'
    result+=$(printf "${1}GATEWAY${3} = $2%s${3}\n" "$gateway")
    result+='\n'
    result+=$(printf "${1}RAM_TOTAL${3} = $2%s${3}\n" "$ram_total")
    result+='\n'
    result+=$(printf "${1}RAM_USED${3} = $2%s${3}\n" "$ram_used")
    result+='\n'
    result+=$(printf "${1}RAM_FREE${3} = $2%s${3}\n" "$ram_free")
    result+='\n'
    result+=$(printf "${1}SPACE_ROOT${3} = $2%s${3}\n" "$space_root")
    result+='\n'
    result+=$(printf "${1}SPACE_ROOT_USED${3} = $2%s${3}\n" "$space_root_used")
    result+='\n'
    result+=$(printf "${1}SPACE_ROOT_FREE${3} = ${2}%s${3}\n" "$space_root_free")
    echo -e "$result"
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
echo "Archive files = " $(find "$1" -type f -name "*.7z" -o -name "*.zip" -o -name "*.rar" -o -name "*.tar" -o -name "*.gz" 2>/dev/null | wc -l)
echo "Symbolic links = "$(find $1 2>/dev/null -type l | wc -l)
echo "TOP 10 files of maximum size arranged in descending order (path, size and type): "
find "$1" -type f -exec du -h {} + 2>/dev/null | sort -hr | head -10 | awk 'BEGIN {i=1} {
    path=$2;
    extension="";
    split(path, arr, ".");
    if (length(arr) > 1) {
        extension=arr[length(arr)];
    }
    if (extension ~/^[0-9]+$|\/|-/) {
        extension="";
    }
    print i" - "path", "$1", "extension;
    i++;
}'

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
    col_one_back=$1
    col_one_font=$2
    col_two_back=$3
    col_two_font=$4
    if [ "$5" != "" ]; then
        error="default"
        col_one_back=""
        col_one_font=""
        col_two_back=""
        col_two_font=""
    fi
# echo $1 $2 $3 $4
echo ""
echo "Column 1 background = $col_one_back$error $(get_color $1)"
echo "Column 1 font color = $col_one_font$error $(get_color $2)"
echo "Column 2 background = $col_two_back$error $(get_color $3)"
echo "Column 2 font color = $col_two_font$error $(get_color $4)"
}



