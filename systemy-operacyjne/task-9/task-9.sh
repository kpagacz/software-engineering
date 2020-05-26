#!/bin/bash

while true
do
# Get terminals used by a user
me=$(whoami)
curr_terminal=$(tty)
curr_terminal=${curr_terminal/'/dev/'/}
terminals=$(ps -u "$me" -o tty --no-headers)

index=0
while read -r line
do
    # echo "$line"
    # echo "$curr_terminal"
    if [[ "$line" != "$curr_terminal" ]]
    then
        user_terminals[$index]=$line
        index=$((index+1))  
    fi
done <<< "$terminals"

user_terminals=($(printf "%s\n" ${user_terminals[@]} | sort -u))

# Print used terminals
counter=1
echo "Currently used terminals:"
for value in "${user_terminals[@]}"
do
    printf "%i  Name: %s\n" "$counter" "$value"
    counter=$((counter+1))
    done

# Terminal choosing
printf "Input number of a terminal you want to know more about: "
read -r choice
choice=$((choice-1))
echo "Processes of terminal ${user_terminals[choice]}"
ps -t ${user_terminals[$choice]} -o tty,pid,ppid,start_time,args | grep -ve "[ ]/init$"

# Sending SIGTERM to processes
echo "Specify processes to kill (by PID): "
read -ra to_kill
kill -15 ${to_kill[@]}

# If terminal is empty then sigterm it 
lines_number=$(ps -t ${user_terminals[$choice]} | wc -l)
if [[ $lines_number -eq 1 ]]
then
    init_to_kill=$(ps -t ${user_terminals[$choice]} -o pid)
    kill -15 $init_to_kill && kill -9 $init_to_kill
fi
done

