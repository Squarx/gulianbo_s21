#!/bin/bash
echo "Writa a path:"
cd ..
read path
if [ -f $path ]
then
    num_str=`wc -l $path | awk '{print $1}'`
    cut -d ' ' -f 1 $path > src/names_un
    names=`sort src/names_un | uniq | wc -l`
    cut -d ' ' -f 1,8 $path > src/sha_uq
    sha_u=`sort src/sha_uq | uniq | wc -l`
    echo ''$num_str''$names''$sha_u''
    rm src/names_un
    rm src/sha_uq
else
    echo "Wrong path!"
fi
    
