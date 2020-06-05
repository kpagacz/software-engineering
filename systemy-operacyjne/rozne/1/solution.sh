#/bin/bash
# Wypisz na ekranie listę wszystkich różnych aktualnie zalogowanych użytkowników w formacie:
# LOGIN --- IMIĘ i NAZWISKO --- UID --- (LICZBA RÓWNOCZESNYCH SESJI) 

users_count=$(who | awk '{ print $1 }' | sort | uniq -c | tr [:blank:] ":" )

printf "LOGIN --- IMIĘ i NAZWISKO --- UID --- (LICZBA RÓWNOCZESNYCH SESJI)\n"
while read -r line
do
    login=$(printf "%s" "$line" | cut -d":" -f8)
    counts=$(printf "%s" "$line" | cut -d":" -f7)

    etc_line=$(iconv -f ISO8859-2 -t UTF-8 /etc/passwd | grep -E "^$login")
    uid=$(cut -d: -f3 <<< "$etc_line")
    name=$(cut -d: -f5 <<< "$etc_line")
    printf "%s --- %s --- %s --- %s\n" "$login" "$name" "$uid" "$counts"
done <<<"$users_count"
