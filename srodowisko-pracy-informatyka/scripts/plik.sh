#!/bin/bash
echo -n "Prosze podac nazwe pliku: "
read nazwa
if [ -e $nazwa ]
then
	echo "Zasob juz istnieje."
else
	echo "Nowy plik" > $nazwa
	cat $nazwa
	fi
