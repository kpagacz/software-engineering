#!/bin/bash

function time_to_date {
    now=$(date +%s)
    future_date=$(date -d "$1" +%s)
    ans=$(( (future_date-now) / 86400))
    if [[ $ans -lt 0 ]]
    then
        echo "Bro, that's in the past!"
    else
        echo $ans days
        fi
}



choice='c'

printf "Choices:\n"
printf "1: something with logins xD\n"
printf "2: how much time until a date specified by you!\n"
printf "e: exit!\n"

while read -n 1 -p "Input your choice: " choice
do
    case $choice in
    1 )
        . zadanie2.sh
        printf "\nInput number of days and one login (ex. 7 login)\n"
        read -a array
        some_function "${array[@]}"
        ;;
    2 )
        printf "\nInput a date in the future (DD/MM/YYYY): "
        read -r date
        echo $date
        time_to_date $date
        ;;
    e )
        echo
        exit ;;
    * )
        printf "\nWrong input!\n" ;;
    esac
done