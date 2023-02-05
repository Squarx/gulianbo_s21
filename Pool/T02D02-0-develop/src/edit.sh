#!/bin/bash
echo "Written way ="
read path
echo "What you want to rewrite"
read repl
echo "What to write"
read wrt
cd ..
if [[ -f $path ]]
then
if [[ $repl != "" ]]
    then
        if [ $wrt!= ""]
        then
            sed -i '' -e 's/'$repl'/'$wrt'/g' $path
            wc -c $path | awk '{print $1}' > src/weight
            date +%F' '%H:%M > src/dat
            openssl sha256 $path | awk '{print $2}' > src/sha
            echo "$1 - `cat src/weight` - `cat src/dat` - `cat src/sha` - sha256" >> src/files.log
            rm src/weight
            rm src/dat
            rm src/sha
        else
            echo "You have to write at least 1 letter to rewrite!"
        fi
    else
        echo "You have to write at least 1 letter to write!"
    fi
else
    echo "Wrong path!"
fi
   
