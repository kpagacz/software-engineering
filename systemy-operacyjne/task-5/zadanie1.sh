#!/bin/bash

suma=0
if (($#<1)) 
then
	echo "Brak parametrow"
	exit 1
fi

myself=`whoami`

for Katalog in $@
do
	if [ -d $Katalog ]
	then
		rozmiar=`ls -l $Katalog | grep -e "^-" | sed 's/[[:blank:]]\+/;/g' | awk -F";" -v me=$myself '$3==me {SUMA+=$5} END{print(SUMA)}'`
		suma=$((suma+rozmiar))
		fi
	done

echo $suma

