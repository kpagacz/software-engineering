/* Zadanie 1 */
select nazwisko
from pracownicy
where id_placowki = 1
intersect
select nazwisko
from pracownicy
where id_placowki = 6;

/* Zadanie 2 */
(select nazwisko "nazwiska - różnice"
from pracownicy join placowki using(id_placowki)
where nazwa = 'BIURO')
minus
(select nazwisko
from pracownicy join placowki using(id_placowki)
where nazwa = 'SKLEP I')
order by 1 asc;

/* Zadanie 3 */
(select nazwisko || '*' nazwisko
from pracownicy join placowki using(id_placowki)
where id_placowki = 1)
union
(select nazwisko
from pracownicy join placowki using(id_placowki)
where id_placowki <> 1)
order by 1;

select nazwisko || case
                   when id_placowki = 1 then '*'
                   else ''
                   end
                   nazwisko
from pracownicy
order by 1;

/* Zadanie 4 */
(select imie, nazwisko, to_char(add_months(data_zatrudnienia, 3), 'dd/mm/yyyy') "DATA SZKOLENIA"
from pracownicy
where mod(id_pracownika, 2) = 0)
union
(select imie, nazwisko, to_char(add_months(data_zatrudnienia, 6), 'dd/mm/yyyy') "DATA SZKOLENIA"
from pracownicy
where mod(id_pracownika, 2) = 1)
order by 2 asc, 1 asc;

/* Zadanie 5 */
select nazwa, avg(pensja) "ŚREDNIA_PENSJA"
from pracownicy join placowki using(id_placowki)
group by nazwa
order by nazwa asc;

select nazwa, avg(pensja) "ŚREDNIA_PENSJA"
from pracownicy join placowki using(id_placowki)
group by rollup(nazwa)
order by nazwa asc;

/* Zadanie 6 */
select to_char(data_urodzenia, 'month'), count(id_pracownika) "LICZBA OSÓB"
from pracownicy
group by rollup(to_char(data_urodzenia, 'month'))
order by 2 asc;

/* Zadanie 7 */
select zawod, plec, avg(pensja) SREDNIA_PENSJA
from pracownicy
group by zawod, plec
order by zawod asc, plec asc;

select zawod, plec, avg(pensja) SREDNIA_PENSJA
from pracownicy
group by rollup(zawod, plec)
order by zawod asc, plec asc;

select zawod, plec, avg(pensja) SREDNIA_PENSJA
from pracownicy
group by cube(zawod, plec)
order by zawod asc, plec asc;

/* Zadanie 8 */
alter session set nls_language='Polish';
select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB"
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by grouping sets((poziom, nazwa), poziom, ())
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB"
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by rollup(poziom, nazwa)
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB"
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by rollup(nazwa, poziom)
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB"
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by grouping sets((poziom, nazwa), nazwa)
order by poziom asc, nazwa asc;

/* Zadanie 9 */
alter session set nls_language='Polish';
select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB", grouping(poziom), grouping(nazwa)
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by grouping sets((poziom, nazwa), poziom, ())
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB", grouping(poziom), grouping(nazwa)
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by rollup(poziom, nazwa)
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB", grouping(poziom), grouping(nazwa)
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by rollup(nazwa, poziom)
order by poziom asc, nazwa asc;

select poziom, nazwa, count(id_pracownika) "LICZBA OSÓB", grouping(poziom), grouping(nazwa)
from pracownicy join placowki using(id_placowki) join wyksztalcenie using(id_wyksztalcenia)
group by grouping sets((poziom, nazwa), nazwa)
order by poziom asc, nazwa asc;

/* Zadanie 10 */
select nazwa, zawod, min(pensja) "MINIMALNA PENSJA"
from pracownicy join placowki using(id_placowki)
group by grouping sets(zawod, nazwa)
order by min(pensja) desc;

select nazwa, zawod, min(pensja) "MINIMALNA PENSJA"
from pracownicy join placowki using(id_placowki)
group by cube(zawod, nazwa)
having (grouping(zawod) > 0 or grouping(nazwa) > 0) and not (grouping(zawod)>0 and grouping(nazwa)>0)
order by min(pensja) desc;

/* Zadanie 11 */
select nazwa, plec, count(id_pracownika) "LICZBA OSÓB"
from pracownicy join uczestnictwo using(id_pracownika) join kursy using(id_kursu)
where data_zatrudnienia > to_date('15/01/2000', 'dd/mm/yyyy')
group by cube(nazwa, plec)
order by nazwa asc, plec asc;

/* Zadanie 12 */
select 
  case
  when nazwa is null then 'WSZYSTKIE PLACOWKI RAZEM'
  else nazwa end,
  avg(pensja) "ŚREDNIA_PENSJA"
from pracownicy join placowki using(id_placowki)
group by rollup(nazwa)
order by nazwa asc;

select 
  case
  when grouping(nazwa) = 1 then 'WSZYSTKIE PLACOWKI RAZEM'
  else nazwa end,
  avg(pensja) "ŚREDNIA_PENSJA"
from pracownicy join placowki using(id_placowki)
group by rollup(nazwa)
order by nazwa asc;