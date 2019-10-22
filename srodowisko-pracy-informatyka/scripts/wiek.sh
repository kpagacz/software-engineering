#!/bin/bash
echo "Podaj wiek"
read wiek
if [ $wiek -lt 0 ]
then
	echo "Bledna wartosc wieku"
elif [ $wiek -lt 18 ]
then
	echo "Osoba niepelnoletnia"
else 
	echo "Osoba pelnoletnia"
	fi
