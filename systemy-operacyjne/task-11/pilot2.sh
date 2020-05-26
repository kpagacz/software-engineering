#!/bin/bash

# getting pid and terminal of maszyna2.sh

pid=$(pgrep maszyna2.sh)
euid=$(ps -o euid $pid)
login=$(getent passwd $euid | cut -d: -f1)
tty=$(ps -o tty --no-headers $pid | tr -d '/')

# echo "$pid $login $tty"

# assigning the tmp directory of maszyna
# and assigning the named pipe

dir=/tmp/"$login"
pipe=/tmp/"$login"/.MASZYNA."$tty"."$pid"

# echo "$dir $pipe"

##############
# input
##############
echo "Hello! This is pilot of the maszyna2.sh!"
echo "Choose your action:"
echo "f - input file to the machine"
echo "m - input text to the machine"
echo "k - end the machine"
echo "s - stop the machine"
echo "c - resume work of the machine"
echo "e - exit this script"

read -r choice

case "$choice" in 
    "f" )
        echo "Input the path to the file"
        kill -USR1 $pid
        read -r path_to_file
        echo "$path_to_file"
        cat "$path_to_file" >> $pipe
        ;;
    "m" )
        echo "Input your text to send to the machine!"
        kill -USR1 $pid
        while read -r line
        do 
            echo "$line" >> $pipe
        done
        ;;
    "k" )
        kill -TERM $pid 
        rm -rf "$dir"
        ;;
    "s" )
        kill -STOP $pid ;;
    "c" )
        kill -CONT $pid ;;
    "e" )
        exit ;;
    * )
        echo "Wrong input!" ;;
esac
