#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

declare -a tests=(
"VAR test_case_cat.txt"
)

declare -a extra=(
"-s test_1_cat.txt"
"-b -e -n -s -t -v test_1_cat.txt"
"-t test_3_cat.txt"
"-n test_2_cat.txt"
"no_file.txt"
"-n -b test_1_cat.txt"
"-s -n -e test_4_cat.txt"
"test_1_cat.txt -n"
"-n test_1_cat.txt"
"-n test_1_cat.txt test_2_cat.txt"
"-v test_5_cat.txt"
)

# Regular Colors
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

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

NC='\033[0m' # No Color

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_cat $t > test_s21_cat.log
    cat $t > test_sys_cat.log
    DIFF_RES="$(diff -s test_s21_cat.log test_sys_cat.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_cat.log and test_sys_cat.log are identical" ]
    then
      (( SUCCESS++ ))
        echo "$IRed$FAIL$NC $IBlue$SUCCESS$NC $IPurple$COUNTER$NC ${On_Green}SUCCESS$NC cat $t"
    else
      (( FAIL++ ))
        echo "$IRed$FAIL$NC $IBlue$SUCCESS $IPurple$COUNTER$NC $On_Red FAIL $NC cat $t"
    fi
    rm test_s21_cat.log test_sys_cat.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

#
 2 параметра
for var1 in b e n s t v
do
    for var2 in b e n s t v
    do

            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                testing $i
            done

    done
done



# 2 сдвоенных параметра
for var1 in b e n s t v
do
    for var2 in b e n s t v
    do

            for i in "${tests[@]}"
            do
                var="-$var1$var2"
                testing $i
            done

    done
done

#смежные
for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
        do
            for var4 in b e n s t v X
            do

                    for i in "${tests[@]}"
                    do
                        var="-$var1$var2$var3$var4 -$var4$var3$var2$var1 -$var1 -$var2 -$var3 -$var4"
                        testing $i
                    done

            done
        done
    done
done



echo "${On_Red}FAIL: $FAIL$NC"
echo "${On_Green}SUCCESS: $SUCCESS$NC"
echo "${On_Purple}ALL: $COUNTER$NC"
