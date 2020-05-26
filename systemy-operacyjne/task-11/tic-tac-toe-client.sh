#!/bin/bash
# Sourcing
source tic-tac-toe-utils.sh

# Welcome
echo "This is a Tic-Tac-Toe client!"

####################
# Directories setup
####################
WDIR=/tmp/$(whoami)/tic-tac-toe
[[ -d "$WDIR" ]] || mkdir -p "$WDIR"
: > client.log

######################
# Pipe to server setup
######################
SERVER="$WDIR"/server-listen
RESPONSE="$WDIR"/$$.connection

######################
# Traps
######################
trap closeConnection SIGTERM SIGINT

client_id=$$

echo "Welcome to Tic-Tac-Toe!"
echo "Choose action:"
echo "c - connect to server"
echo "e - exit"
echo "When prompted for move you can input e to exit"

read -r choice
connection_established=0
case $choice in 
    c )
        echo "$client_id:ConnectionRequest" > "$SERVER"
        # need to wait a bit for the pipe to be established
        counter=0
        while [ ! -p "$RESPONSE" ]
        do 
            sleep 0.5
            counter=$((counter+1))
            if [[ counter -eq 5 ]]
            then
                echo "Couldn't establish connection with the server"
                exit 0
            fi
        done
        r=$(cat $RESPONSE)

        case "$r" in
        # too many players
        "$client_id:$too_many_players" )
            echo "Server capacity reached. Try again later."
            exit
            ;;
        # connection gut
        "$client_id:$accepted" )
            echo "Connection established."
            connection_established=1
            clientStartGame
            ;;
        esac
        ;;
    e)
        echo "Good bye!"
        exit 0
        ;;
    * )
        echo "Wrong input!!"
        ;;
esac