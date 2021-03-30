/* Test on table pracownicy: http://math.uni.lodz.pl/~astasiak/psb_2021/tabele_firma.sql */
select imie, nazwisko, to_char(data_zatrudnienia, 'Q') "Kwartał", LEVEL
from pracownicy
start with nazwisko='BALCERZYK' and plec='K'
connect by id_szefa=prior id_pracownika
order by LEVEL asc, nazwisko asc;

select plec, lower(poziom), round(avg(pensja), 2)
from pracownicy join wyksztalcenie using(id_wyksztalcenia)
where mod(id_pracownika, 2) = 0
group by grouping sets((plec, poziom), plec, poziom)
order by 3 asc;

select imie, nazwisko, lower(plec), case
                             when length(replace(nazwa, ' ', '')) < 7 then add_months(data_zatrudnienia, 5)
                             else add_months(data_zatrudnienia, 10)
                             end "Planowana podwyżka"
from pracownicy join placowki using(id_placowki)
order by nazwisko asc, imie asc;

select imie, nazwisko, to_char(data_urodzenia, 'DD fmmonth YYYY') "Data urodzenia"
from pracownicy p
where zawod='SPRZEDAWCA' AND exists(select 1 from pracownicy where id_szefa=p.id_pracownika)
order by nazwisko asc, imie asc;