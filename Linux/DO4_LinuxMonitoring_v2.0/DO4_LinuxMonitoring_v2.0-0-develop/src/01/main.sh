#!/bin/bash
# shellcheck source=./func.sh
source ./func.sh
# bash  main.sh /home/g/test 4 az 5 az.az 3kb
checks "$@"
optimizedGeneration  "$@"