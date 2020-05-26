#!/bin/bash

case $# in
    [23] )
        if [[ -w "$1" || -w "$2" ]]
        then
            : > $1
            : > $2
        fi
        ;;
    * )
        printf "Wrong number of arguments.\n"
        printf "Usage: command output-even output-odd [input file]\n"
        exit -1
        ;;
esac

if [[ $# -eq 3 ]]
then 
    exec 3<$3
else
    exec 3<&0
fi 

counter=0
while IFS="" read -r -u 3 line || [ -n "$line" ]
do
    #printf 'Counter: %i\n' "$counter"
    if [ $((counter % 2)) -eq 1 ]
    then
        printf '%s\n' "${line^^}" >> $1
    else
        out=$(printf "%s" "$line" | rev)
        printf '%s\n' "$out" >> $2
    fi
    counter=$((counter+1))
done

exec 3<&-




    
