#!/bin/bash
if [ $# -eq 1 ] && [ $1 -eq $1 2>/dev/null ]
then
	echo "Kwadrat liczby $1 rowna sie $[$1*$1]."
else
	echo "Prosze podac jedna liczbe calkowita jako argument skryptu."
	fi
