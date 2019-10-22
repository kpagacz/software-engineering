#!/bin/bash
echo -n "Podaj liczbe: "
read x
#sprawdzanie,czy rzeczywiscie podano liczbe

if [ $x -eq $x  2>/dev/null ]
then
		echo Podano liczbe $x
	else
			echo $x nie jest liczba
			fi


