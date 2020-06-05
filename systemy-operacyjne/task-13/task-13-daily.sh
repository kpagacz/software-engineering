#/bin/bash

TO_ARCHIVE="$HOME/KATALOGI.lista"
EXCLUSION="$HOME/WYKLUCZENIA.lista"
REPORT="$HOME/ARCHIWUM/raporty"
DAILY_ARCHIVE_DIR="$HOME/ARCHIWA-DZIENNE"
ARCHIVE_DIR="$HOME/ARCHIWUM"

############################
# Make dirs if not existing
############################
[ -d "$DAILY_ARCHIVE_DIR" ] || mkdir "$DAILY_ARCHIVE_DIR"
[ -d "$ARCHIVE_DIR" ] || mkdir "$ARCHIVE_DIR"
############################
# Print current date to the report
############################
date=$(date +%Y-%m-%d)
echo "---------------------" >> "$REPORT"
echo "$date : dzienne" >> "$REPORT"
echo "---------------------" >> "$REPORT"
############################
# Find files modified in the last 24 h
# Tar the catalogues and output to the report
############################
cd "$DAILY_ARCHIVE_DIR"
while read -r dir
do
    # echo $dir
    if [ -d "$dir" ]
    then 
        find "$dir" -type f -mtime -1 | tar -uvf "dzienne-$date.tar" --exclude-from "$EXCLUSION" -T -  1>>"$REPORT" 2>/dev/null
    fi
done < "$TO_ARCHIVE"
# Gzip the archive
gzip "dzienne-$date.tar"