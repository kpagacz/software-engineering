#!/bin/bash
source tic-tac-toe-utils.sh

echo "This is a Tic-Tac-Toe server!"

##################
# Info
##################
# Tables:
#     board contains current state of the game
#     id contains ids of the players in the game
#     players contain pipes to the players in the game

####################
# Directories setup
####################
WDIR=/tmp/$(whoami)/tic-tac-toe
[[ -d "$WDIR" ]] || mkdir -p "$WDIR"

######################
# Incoming pipe setup
######################
INCOMING="$WDIR"/server-listen
mkfifo -m 600 "$INCOMING" 2>/dev/null || (rm -rf "$INCOMING"; mkfifo -m 600 "$INCOMING")

####################
# Trapping signals
####################
trap "exitRoutine" SIGTERM SIGABRT SIGINT

####################
# Listening loop
####################
currently_playing=0
echo "Start listening at $INCOMING"
while true
do
    in=$(cat "$INCOMING")
    echo "Incoming connection: $in"
    in_message=$(echo $in | cut -d: -f2)
    if [[ $currently_playing -eq 0 && "$in_message" == "ConnectionRequest" ]] 2>/dev/null
    then
        echo "Noone playing"
        registerPlayer1
        serverStartGame
    else
        echo "Players in game"
        refuseConnection
    fi
done

exitRoutine