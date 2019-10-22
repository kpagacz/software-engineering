#!/bin/bash

echo "Sprawdzamy, czy w katalogu glownym uzytkownika"
echo "istnieje plik lub katalog o podanej nazwie"

cd ~

echo -n "Podaj nazwe pliku lub katalogu: "
read nazwa

if [ -f  $nazwa ]
then 
	   echo "Plik o nazwie $nazwa istnieje w Twoim katalogu domowym"
	      ls -l  $nazwa
      elif  [ -d $nazwa ]
      then 
	         echo "Jest taki katalog. Podajemy jego zawartosc"
		    ls -lR $nazwa
	    else 
		       echo "Nie ma pliku ani katalogu o podanej przez Ciebie nazwie"
		       fi

# mozna zaczac od testowania istnienia zasobu o podanej nazwie
# stosujac operator -e
