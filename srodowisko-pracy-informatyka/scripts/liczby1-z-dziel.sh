#!/bin/bash
echo "Suma:$[$1+$2]. Roznica:$[$1-$2]. Iloczyn:$(($1*$2)). "
if [ $2 -ne 0 ]
then
	echo "Iloraz: $[$1/$2]."
	fi
