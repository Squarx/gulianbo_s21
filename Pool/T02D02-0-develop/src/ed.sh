#!/bin/bash
#echo "Written way =" $1
#echo "What you want to rewrite" $2
#echo "What to write" $3
cd ..
wc -c $1 | awk '{print $1}' > weight
#echo `cat weight`
date +%F' '%H:%M > dat
#echo `cat dat`
openssl sha256 $1 | awk '{print $2}' > sha
#echo `cat sha`
echo "$1 - `cat weight` - `cat dat` - `cat sha` - sha256" >> src/est.txt
#cat a
#| awk '{print '$1'}'
#cat path.p
#date +%F' '%H:%M
#cat path.p
#openssl sha256 $1 | awk '{print $2}' >> path.txt
#echo "$1 - '$weight' - '$da'- '$sha' - sha256" >> $1
#open /Users/gulianbo/T02D02-0/src/est.txt
#date +%F' '%H:%M >> path.txt
#wc -c $1 | awk '{print $1}' >> path.txt
#cat path.txt
