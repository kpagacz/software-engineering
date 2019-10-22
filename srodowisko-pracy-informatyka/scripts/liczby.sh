#!/bin/bash
echo Podaj dwie liczby calkowite przedzielone spacja
read liczba1 liczba2
echo Liczby to: $liczba1 oraz $liczba2. Suma: $[liczba1+liczba2].
echo Roznica: $[liczba1-liczba2]. Iloczyn:$[liczba1*liczba2]
if [ $liczba2 -ne 0 ]
then
	echo Iloraz: $[liczba1 / liczba2]
else
	echo Nie mozna dzielic przez zero
	fi

