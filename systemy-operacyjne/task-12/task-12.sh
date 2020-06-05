#/bin/bash
WDIR="~/home-size"
cd "$WDIR"
FILE="ZMIANY.txt"
HOLIDAYS="holidays"
UTILS=$(pwd)"/task-12-utils.sh"

# check if in holidays
month_day=$(date +%m/%d)
in_holidays=0
while read -r single_date
do  
    if [ "$month_day" == "$single_date" ]
    then
        in_holidays=1
        break;
    fi
done < "$HOLIDAYS"

# echo "In holidays?: $in_holidays"
weekday=$(date +%w)
if [[ ($weekday -eq 6 || $weekday -eq 7) || $in_holidays -eq 1 ]]
then 
    # launch output at 23:59
    echo "Weekend lub święto"
    at 23:59 -f "$UTILS"

else
    # launch two times at 08:05 and 18:05
    echo "workday"
    at 8:05 -f "$UTILS"
    at 18:05 -f "$UTILS"
fi
