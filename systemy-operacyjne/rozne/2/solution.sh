#/bin/bash

for i in $(seq $1 $2)
do
    grepped=$(grep -E ":$i:" /etc/passwd)
    found=0
    while read -r line
    do
        uid=$(cut -d: -f3 <<< "$line")
        if [[ $uid -eq $i ]]
        then 
            found=1
            break;
        fi
    done <<<"$grepped"

    if [[ found -eq 0 ]]
    then
        printf "%s " "$i"
    fi
done
printf "\n"