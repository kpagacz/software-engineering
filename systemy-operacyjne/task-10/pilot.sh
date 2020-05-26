#!/bin/bash



if [[ $# -ne 1 ]]
then
    printf "This script takes one argument - output directory of the machine!\n"
    exit
fi

dir="$1"
choice='c'

while [[ choice != 'e' ]]
do
    printf "Welcome to the machine!\n"
    printf "Machine outputs different words to the output directory.\n"
    
    printf "You can control what word the machine prints! Choose your word:\n"
    printf "0   pong\n"
    printf "1   ping\n"
    printf "2   hip\n"
    printf "3   hop\n"
    printf "stop    stops the machine\n"
    printf "start   resumes the stopped machine\n"
    printf "e   kills the machine. Muahaha\n"

    read -r choice
    echo $choice

    case "$choice" in
        [0-3] )
            killall -$((35+choice)) mojamaszyna.sh ;;
        "stop" )
            killall -SIGSTOP mojamaszyna.sh ;;
        "start" )
            killall -SIGCONT mojamaszyna.sh ;;
        "e" )
            killall -SIGTERM mojamaszyna.sh && killall -SIGKILL mojamaszyna.sh
            rm -rf $dir
            exit 0 ;;
        * )
            printf "Wrong input!\n" ;;
    esac

done