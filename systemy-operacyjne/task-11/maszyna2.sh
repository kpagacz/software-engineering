#!/bin/bash

ILE=0
PT=0

TERMINAL=$(tty |sed 's/^\/dev\///' | tr -d '/' )

MDIR=/tmp/$USER #nazwa katalogu tymczasowego 

[ -d $MDIR ] || mkdir $MDIR

WE=$MDIR/.MASZYNA.$TERMINAL.$$ #nazwa łącza - odwołuje się do nazwy terminala i PID skryptu

if [ -f $MDIR/pid ]
	then
		echo Maszyna juz uruchomiona
		exit
	else
		echo $$ >$MDIR/pid  #umożliwia stwierdzenie uruchomienia skryptu
	fi


trap 'zpotoku' USR1
trap 'zatrzymaj'  TERM INT STOP ABRT #dla STOP nie zadziała!

function zpotoku() {
    PT=1
    czysc
    echo -e "\tOTRZYMANE KOMUNIKATY:"
    exec 5<$WE
}

function czysc() {
    echo -ne "\r                                                                          \r"
}

function gwiazdki()  {
	    for ((i=1;i<=30;i++))
		do
			echo -ne "* "
			sleep 0.2
		done
	    czysc
}

function zatrzymaj () {
	echo
	echo Maszyna kończy dzialanie
	echo
	echo "Liczba otrzymanych wierszy: $ILE"
	rm -f $MDIR/pid 
	exec 5<&-
	unlink $WE
	exit
	}

mkfifo -m 600 $WE 2>/dev/null || ( rm -rf $WE; mkfifo -m 600 $WE )

    while true
	do
	    if ((PT==1))
		then
		    B=`cat<&5`
		fi
	    if [ -z "$B" ]
		then
		    gwiazdki
		else
		    ((ILE+=1))
		    echo "$B"
	    fi
	done

zatrzymaj