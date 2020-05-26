#!/bin/bash

function some_function {
n=$1
shift

if [[ n -le 0 ]]
then
	echo "Pierwszy argument ma być liczbą dodatnią."
	exit 1
	fi

for login in $@
do
	imie=`iconv -f ISO8859-2 -t UTF-8 /etc/passwd | grep -e "^$login:" | cut -d: -f 5`
	if [[ -z $imie ]]
	then
		echo "Nie ma takiego loginu lub imienia użytkownika dla loginu: $login"
		continue
		fi
	echo "`last -$n | head -n -2 | sed 's/[[:blank:]]\+/;/g' | grep -e "^$login;" | awk -v id="$login" -v im="$imie" -F ";" 'BEGIN {printf "%s -- %s \n", id, im}{printf "    %s %s %s %s %s %s %s \n", $4, $5, $6, $7, $8, $9, $10 }'`"
	       
done
}
