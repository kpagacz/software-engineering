#!/bin/bash
source tic-tac-toe-utils-2players.sh

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
    if [ "$in_message" == "ConnectionRequest" ] 2>/dev/null
    then
        case $currently_playing in
        0 )
            echo "Noone playing"
            registerPlayer1
            echo "Currently in game: $currently_playing"
            ;;
        1 )
            echo "1 player already in game"
            registerPlayer2
            echo "Currently in game: $currently_playing"
            serverStartGame
            ;;
        * )
            echo "Players in game"
            refuseConnection
            ;;
        esac
    fi
    if [ "$in_message" == "$exit_game" ]
    then
        drop_players
    fi
done

exitRoutine