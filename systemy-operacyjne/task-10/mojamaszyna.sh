#!/bin/bash

if [[ $# -ne 1 ]]
then
        printf "Needs one argument - the output directory.\n"
        exit
        fi

MDIR="$1"

ILE=10000
TTL=$ILE
B="ping"

[ -d $MDIR ] || mkdir $MDIR

if [ -f $MDIR/pid ]
        then
                echo "Maszyna źle zatrzymana poprzednio - usuń ręcznie plik \"pid\"!"
                exit
        else
                echo $$ >$MDIR/pid
        fi

trap 'B=pong;' 35
trap 'B=ping;' 36
trap 'B=hip;' 37
trap 'B=hop;' 38
trap 'Zatrzymaj;' TERM INT  #wykonanie funkcji Zatrzymaj w miejscu sygnałów SIGTERM, SIGINT

function Zatrzymaj () {
        echo -e "\n\nMaszyna kończy działanie\n"
        echo -e "Liczba pełnych cykli: $(($ILE-$TTL))\n"
        rm -f $MDIR/pid     #usuwanie tymczasowego pliku na zakończenie
        exit
        }

while [ $TTL -gt 0 ]
    do
        for ((i=1;i<=6;i++))
                do
                        echo -ne "$B\t"
                        sleep 1
                done
        echo -ne "\r                                                                              \r"
        (( TTL-=1))
    done
Zatrzymaj