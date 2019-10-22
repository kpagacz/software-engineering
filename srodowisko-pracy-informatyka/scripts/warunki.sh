#warrunki
echo -n "Podaj liczbe calkowita z przedzialu (0, 20): "
read li
if [ $li -gt 0 ] && [ $li -lt 20 ]
then
echo -e "\tOK. Podano liczbe z przedzialu (0,20)."
else
echo -e "\tZle.Podana liczba nie nalezy do przedzialu (0,20)."
fi
# Zastosowane opcje dla echo:
#______________________________
# -n	znak nie jest wysylany do nowej linii
# -e	wlacza interpretacje znakow specjalnych
#
# Wybrane znaki specjalne:
#__________________________
# \t	tabulacja pozioma
# \v	tabulacja pionowa
# \a	sygnal
# \b	backspace
#
# Operatory porownywania liczb calkowitych:
#___________________________________________
# -eq	=			
# -ne	rozne, czyli ~ =
# -gt	>
# -lt	<
# -ge	>=
# -le	<=
#____________________________________________
# Operator koniunkcji		&&
# Operator alternatywy		||
