#!/bin/bash

################
# SERVER
################
function exitRoutine() {
    echo "Server stopping"
    drop_players
    echo "Clearing working directories"
    unlink $INCOMING
    rm -rf "$WDIR"
    echo "Server stopped"
    exit
}

function registerPlayer1() {
    echo "Registering Player 1"
    id[0]=$(echo $in | cut -d: -f1)
    PLAYER1_CONNECTION="$WDIR"/"${id[0]}".connection
    mkfifo -m 600 "$PLAYER1_CONNECTION" 2>/dev/null || (rm -rf "$PLAYER1_CONNECTION"; mkfifo -m 600 "$WDIR/$PLAYER1_CONNECTION")
    echo "${id[0]}:$accepted" > "$PLAYER1_CONNECTION"
    sleep 0.2
    echo "Registered Player 1: ${id[0]}"
    currently_playing=$((currently_playing+1))
}

function registerPlayer2() {
    echo "Registering Player 2"
    id[1]=$(echo $in | cut -d: -f1)
    PLAYER2_CONNECTION="$WDIR"/"${id[1]}".connection
    mkfifo -m 600 "$PLAYER2_CONNECTION" 2>/dev/null || (rm -rf "$PLAYER2_CONNECTION"; mkfifo -m 600 "$WDIR/$PLAYER2_CONNECTION")
    echo "${id[1]}:$accepted" > "$PLAYER2_CONNECTION"
    sleep 0.2
    echo "Registered Player 2: ${id[1]}"
    currently_playing=$((currently_playing+1))
}

function refuseConnection() {
    echo "Refusing connection"
    id=$(echo $in | cut -d: -f1)
    connection=$WDIR/${id}.connection
    mkfifo -m 600 "$connection" 2>/dev/null || (rm -rf "$connection"; mkfifo -m 600 "$connection")
    echo "$id:$too_many_players" > "$connection"
    echo "Connection refused"
}

function serverStartGame() {
    echo "Starting the game"
    players[0]="$PLAYER1_CONNECTION"
    players[1]="$PLAYER2_CONNECTION"
    # Randomize starting player
    starting_player=$((RANDOM%2))
    board=(0 0 0 0 0 0 0 0 0)
    move_counter=0
    game_finished=0
    echo "Starting player: $starting_player"
    while [[ $game_finished -eq 0 ]]
    do
        echo "Move: $move_counter"
        current_player=$(((starting_player+move_counter)%2))
        echo "Current player: $current_player"
        if [[ $current_player -eq 0 ]]
        then
            promptPlayerForMove
            receivePlayerMove
        fi
        isGameFinished
        move_counter=$((move_counter+1))
        echo "Current board"
        echo "${board[@]}"
        echo "Current game result: $game_finished"
        if [[ $game_finished -ne 0 ]]
        then
            case $game_finished in
            [12] )
                echo "Game ended."
                echo "P$game_finished won"
                for player in $players
                do
                    echo "END:$game_end" > $player
                    sleep 0.2
                    echo ":MessageStart" > $player
                    sleep 0.2
                    echo ":${board[@]}" > $player
                    sleep 0.2
                    echo "Game ended. P$game_finished won" > $player
                    sleep 0.2
                    echo ":MessageEnd" > $player
                    sleep 0.2
                    drop_players
                done
                ;;
            3 )
                echo "Game aborted"
                for player in $players
                do
                    echo "END:$game_end" > $player
                    sleep 0.2
                    echo ":MessageStart" > $player
                    sleep 0.2
                    echo ":Game aborted" > $player
                    sleep 0.2
                    echo ":MessageEnd" > $player
                    sleep 0.2
                    drop_players
                done
                ;;
            * )
                echo "Unknown game state. Closing"
                exitRoutine
                ;;
            esac
        fi
    done

}

function promptPlayerForMove() {
    echo "${id[current_player]}:MessageStart" > ${players[current_player]}
    sleep 0.2   
    echo "${id[current_player]}:Current board" > ${players[current_player]}
    sleep 0.2
    # echo "${id[current_player]}:MessageEnd" > ${players[current_player]}
    sleep 0.2
    # echo "${id[current_player]}:MessageBoard" > ${players[current_player]}
    sleep 0.2
    echo "${id[current_player]}:${board[@]}" > ${players[current_player]}
    sleep 0.2
    # echo "${id[current_player]}:MessageStart" > ${players[current_player]}
    sleep 0.2
    echo "${id[current_player]}:Your move!" > ${players[current_player]}
    sleep 0.2
    echo "${id[current_player]}:MessageEnd" > ${players[current_player]}
    sleep 0.2
    echo "${id[current_player]}:$move_prompt" > ${players[current_player]}
    sleep 0.2
}

function receivePlayerMove() {
    validated=0
    while [[ $validated -eq 0 ]]
    do
        r=$(cat $INCOMING)
        echo "Response: $r"
        r_id=$(echo $r | cut -d: -f1)
        if [[ $r_id -eq ${id[current_player]} ]]
        then 
            message=$(echo $r | cut -d: -f2)
            echo "$message"
            case "$message" in
            "$send_move" )
                move=$(echo $r | cut -d: -f3)
                echo "Move received: $move"
                isMoveAllowed
                if [[ $validated -eq 1 ]] 
                then
                    board[$((move))]="P$((current_player+1))"
                else
                    promptPlayerForMove
                fi
                ;;
            "$exit_game" )
                drop_players
                validated=1
                game_finished=3
                ;;
            *)
                echo "Wrong client response. Dropping players"
                drop_players
                ;;
            esac
        fi
    done

}

function serverMakeMove() {
    rand=$((RANDOM%9))
    moved=0
    while [[ moved -eq 0 ]]
    do
        if [[ ${board[rand]} != "P1" && ${board[rand]} != "P2" ]]
        then 
            board[rand]="P2"
            moved=1
        else
            rand=$((RANDOM%9))
        fi 
    done
}

function isGameFinished() {
    # horizontal
    for i in $(seq 0 3)
    do
        if [[ ${board[0+i]} == "P1" && ${board[1+i]} == "P1" && ${board[2+i]} == "P1" ]]
        then
            game_finished=1
        fi
    done

    for i in $(seq 0 3)
    do
        if [[ ${board[0+i]} == "P2" && ${board[1+i]} == "P2" && ${board[2+i]} == "P2" ]]
        then
            game_finished=2
        fi
    done

    # vertical
    for i in $(seq 0 3)
    do
        if [[ ${board[0+i]} == "P1" && ${board[3+i]} == "P1" && ${board[6+i]} == "P1" ]]
        then
            game_finished=1
        fi
    done

    for i in $(seq 0 3)
    do
        if [[ ${board[0+i]} == "P2" && ${board[3+i]} == "P2" && ${board[6+i]} == "P2" ]]
        then
            game_finished=2
        fi
    done

    # diagonal
    if [[ ${board[0]} == "P1" && ${board[4]} == "P1" && ${board[8]} == "P1" ]]
    then
        game_finished=1
    fi

    if [[ ${board[0]} == "P2" && ${board[4]} == "P2" && ${board[8]} == "P2" ]]
    then
        game_finished=2
    fi

    if [[ ${board[2]} == "P1" && ${board[4]} == "P1" && ${board[6]} == "P1" ]]
    then
        game_finished=1
    fi

    if [[ ${board[2]} == "P2" && ${board[4]} == "P2" && ${board[6]} == "P2" ]]
    then
        game_finished=2
    fi    
}

function drop_players () {
    echo "Dropping players"
    for player_number in $(seq 0 $((currently_playing-1)))
    do
        echo "Sending exit game signal to: ${players[player_number]}"
        echo "END:$exit_game" > ${players[player_number]}
        sleep 0.2
        currently_playing=$((currently_playing-1))
        unlink ${players[player_number]}
    done
    echo "Dropped players"
}

function isMoveAllowed() {
    echo "Checking if move is allowed"
    echo "Current value at this move:${board[$move]}"
    if [ "${board[$move]}" == "0" ]
    then
        echo "Move allowed"
        validated=1
    else
        echo "Move not allowed"
    fi
}

####################
# CLIENT
####################
function clientStartGame() {
    echo "Starting the game"
    while true
    do
        server_response=$(cat "$RESPONSE" | cut -d: -f2)
        echo $server_response >> client.log
        case "$server_response" in
        "MessageStart" )
            message=$(cat "$RESPONSE" | cut -d: -f2)
            while [ ! "$message" == "MessageEnd" ]
            do
                echo "$message"
                message=$(cat "$RESPONSE" | cut -d: -f2)
            done
            ;;
        "$move_prompt" )
            sendMove
            ;;
        "$game_end" )
            ;;
        "$exit_game" )
            echo "Server initiated shutdown."
            exit
            ;;
        * )
            echo "Unrecognized server response"
            exit
        esac
    done
}

function sendMove() {
    is_number=0
    # Input and validation
    while [[ $is_number -eq 0 ]]
    do
        echo "Input your move (number from 0 to 8)"
        read -r move
        [ $move == "e" ] && closeConnection
        if [[ "$move" =~ $valid_moves ]] 
        then
            is_number=1
        fi
    done

    echo "$client_id:$send_move:$move" > "$SERVER"
    sleep 0.2
}

function closeConnection() {
    echo "Closing client"
    if [[ $connection_established -eq 1 ]]
        then
        [[ -p "$SERVER" ]] && (echo "$client_id:$exit_game" > "$SERVER"; sleep 0.2)
        if [[ -p "$RESPONSE" ]]
        then
            r_mess=$(cat $RESPONSE | cut -d: -f2)
            while ! [[ $r_mess == "$exit_game" ]]
            do
                sleep 0.2
                r_mess=$(cat $RESPONSE | cut -d: -f2)
            done
        fi
    fi
    exit
}


#######################
# Responses
#######################
too_many_players="ConnectionRefusedPlayersCapacityReached"
accepted="ConnectionAccepted"
move_prompt="MovePrompt"
send_move="SendMove"
exit_game="ExitGame"
game_end="GameEnd"


#######################
# Valid moves
#######################
valid_moves="^[0-8]$"