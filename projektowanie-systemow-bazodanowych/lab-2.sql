/* Zadanie 1 */
select nazwisko, imie, LEVEL
from pracownicy
start with id_szefa is null
connect by id_szefa = prior id_pracownika
order by level asc, nazwisko asc;

/* Zadanie 2 */
select nazwisko, imie, LEVEL
from pracownicy
start with nazwisko = 'KLIMCZAK' and plec='K'
connect by id_szefa = prior id_pracownika
order by level asc;

select nazwisko, imie, LEVEL
from pracownicy
start with nazwisko = 'RACZKOWSKA' and plec='K'
connect by id_szefa = prior id_pracownika
order by level asc;

/* Zadanie 3 */
select nazwisko, imie, LEVEL
from pracownicy
start with nazwisko = 'ZATORSKI' and plec='M'
connect by id_pracownika = prior id_szefa
order by level asc, nazwisko asc;

/* Zadanie 4 */
select lpad(nazwisko, length(nazwisko) + level), imie, LEVEL
from pracownicy
start with nazwisko = 'ZATORSKI' and plec='M'
connect by id_pracownika = prior id_szefa
order by level asc, nazwisko asc;

/* Zadanie 6 */
select distinct(nazwa)
from pracownicy join uczestnictwo using (id_pracownika) join kursy using (id_kursu)
where months_between(sysdate, data_urodzenia) / 12 > 60;

/* Zadanie 7 */
select nazwa, count(id_pracownika) "LICZBA OSÓB"
from pracownicy full outer join placowki using(id_placowki)
group by nazwa
order by 2 desc;

/* Zadanie 8 */
select p.nazwisko, p2.nazwisko
from pracownicy p join pracownicy p2 on p.id_szefa = p2.id_pracownika
order by p2.nazwisko asc, p.nazwisko asc;

/* Zadanie 9 */
select p.nazwisko, p2.nazwisko
from pracownicy p left join pracownicy p2 on p.id_szefa = p2.id_pracownika
order by p2.nazwisko asc, p.nazwisko asc;

/* Zadanie 10 */
select nazwisko
from pracownicy
where id_szefa = (select id_pracownika from pracownicy where nazwisko = 'KONECKI')
order by nazwisko;

/* Zadanie 11 */
select p1.imie, p1.nazwisko
from pracownicy p1 join pracownicy p2 on p1.id_szefa = p2.id_pracownika
where p1.data_zatrudnienia < p2.data_zatrudnienia
order by p1.nazwisko asc, p1.imie asc;

/* Zadanie 12 */
select nazwisko, pesel
from pracownicy p
where exists (select 1 from pracownicy where id_szefa = p.id_pracownika)
order by nazwisko asc;

/* Zadanie 13 */
select imie, nazwisko, plec
from pracownicy
where id_pracownika not in (select distinct id_szefa
                            from pracownicy
                            where id_szefa is not null)
order by nazwisko asc, imie asc;            

/* Zadanie 14 */
select imie, nazwisko
from pracownicy p
where exists (select 1
              from pracownicy
              where id_szefa = p.id_pracownika)
order by nazwisko asc, imie asc;

/* Zadanie 15 */
select nazwisko
from pracownicy p
where plec='K' and exists (select 1
                           from pracownicy
                           where id_szefa = p.id_pracownika)
order by nazwisko asc;   


/* Zadanie 16 */
select nazwisko
from pracownicy p
where p.id_szefa in (select id_pracownika
                     from pracownicy
                     where plec='K' and zawod='SPRZEDAWCA')
order by nazwisko asc;   

/* Zadanie 17 */
select nazwisko, pensja, (select count(id_pracownika)
                          from pracownicy
                          where p.zawod = zawod) "liczba osób w zawodzie",
                          (select round(avg(pensja), 2)
                          from pracownicy
                          where p.zawod = zawod) "średnia pensja w zawodzie"
from pracownicy p
order by nazwisko asc;
