#/bin/bash
FILE="ZMIANY.txt"
HOLIDAYS="holidays"

function calculateTotal {
    total=$(du -bs ~ | tr [:blank:] "*" | cut -d"*" -f1)
}

function homeDirSizeToFile {
    # total bytes
    calculateTotal

    # get previous size
    if [ -f "$FILE" ]
    then
        lines=$(wc -l "$FILE" | awk '{print $1}')
        # echo "Linie w znaki.txt: $lines"
        if [[ lines -ge 2 ]]
        then
            next_to_last=$(tail -n 1 "$FILE")
            # echo "$next_to_last"
            # finding indices of the bytes
            prefix=${next_to_last%%": "*}
            beginning=$((${#prefix}+2))
            # echo "Begin: $beginning"
            sufix=${next_to_last%%" ---"*}
            end=$((${#sufix}))
            length=$((end-beginning))
            # echo "length: $length"
            previous=${next_to_last:beginning:length}
        else
            previous=0
        fi
    else
        previous=0
    fi

    # format line
    line=$(date +%Y-%m-%d_%H:%M)": $total --- "$((total-previous))
    line_length=${#line}
    # echo "Length of line: $line_length"
    # echo "Line: $line"
    

    # output -
    for i in $(seq 1 $line_length)
    do
        printf "-" >> "$FILE"
    done
    printf "\n%s\n" "$line" >> "$FILE"
}

homeDirSizeToFile