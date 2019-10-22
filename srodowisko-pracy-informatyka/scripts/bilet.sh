#!/bin/bash
echo "Podaj wiek"
read wiek
if [ $wiek -lt 0 ]
then
	echo "Prosze wpisac dodatnia liczbe wieku"
	exit
	fi

if [ $wiek -le 7 ] || [ $wiek -ge 65 ]
then 
	echo "Nie trzeba kupowac biletu"
else
	echo "Trzeba kupic bilet"
	fi
