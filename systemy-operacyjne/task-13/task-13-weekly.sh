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
# Read the list of files in dzienne
############################
cd ~
archives=$(find "$DAILY_ARCHIVE_DIR" -type f -mtime -7)
for archive in "$archives"
do
    this=$(tar -tf "$archive")
    files="$files"$'\n'"$this"
done
files=$(echo "$files" | tail -n +2 | sort -u | sed 's/^/\//')

##############################
# Tar the files
# Output list to the report
##############################
echo "---------------------" >> "$REPORT"
echo "$(date +%Y-%m-%d) : pełne" >> "$REPORT"
echo "---------------------" >> "$REPORT"
echo "$files" | tar -zcvf "$ARCHIVE_DIR/pelne.tar.gz" --exclude-from "$EXCLUSION" -T - 1>>"$REPORT" 2>/dev/null