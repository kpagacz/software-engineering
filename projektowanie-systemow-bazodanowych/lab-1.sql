/* Zadanie 1 */
select round(sqrt(3.2 * 3.2 + 4.6 * 4.6), 5) from dual;

select * from user_tables;
select * from pracownicy;

/* Zadanie 2 */
select initcap(imie) || ' ' || initcap(nazwisko) as osoba, id_pracownika, pensja
from pracownicy
where dodatek is null
and mod(id_pracownika, 2) = 1
order by pensja desc;

/* Zadanie 3 */
select imie, nazwisko, 12 * nvl(pensja, 0) as "ROCZNE ZAROBKI", 12 * nvl(pensja, 0) + nvl(dodatek, 0) as "CAŁKOWITE ROCZNE ZAROBKI"
from pracownicy
where to_char(data_zatrudnienia, 'Q') = '3'
order by nazwisko asc, imie asc;

/* Zadanie 4 */
select initcap(substr(imie, 1, 1)) || '.' || initcap(substr(nazwisko, 1, 1)) || '.' as "Inicjały"
from pracownicy
where lower(zawod) like '%r';

select initcap(substr(imie, 1, 1)) || '.' || initcap(substr(nazwisko, 1, 1)) || '.' as "Inicjały"
from pracownicy
where substr(lower(zawod), -1, 1) = 'r';

/* Zadanie 5 */
select to_char(sysdate, 'DD RM YYYY HH24:MI:SS') as "AKTUALNA DATA I CZAS" from dual;

/* Zadanie 6 */
select imie, nazwisko, case substr(lower(imie), -1, 1) when 'a' then 'KOBIETA' else 'MEZCZYZNA' end "PŁEĆ" 
from pracownicy;

/* Zadanie 7 */
select imie, nazwisko, zawod
from pracownicy
where length(nazwisko) = (select max(length(nazwisko)) from pracownicy);

/* Zadanie 8 */
select lpad(nazwisko, length(nazwisko) * 2, ' ') from pracownicy;

/* Zadanie 9 */
select rpad(imie || ' ' || nazwisko, length(imie) + length(nazwisko) + 1 + nvl(id_placowki, 0), '*') as NAPIS from pracownicy;

/* Zadanie 10 */
alter session set nls_date_format='DD MON YYYY HH24:MI';

/* Zadanie 11 */
select data_urodzenia D_UR, data_urodzenia + 3 "D_UR + 3 dni", data_urodzenia - 5 "D_UR - 5 dni", add_months(data_urodzenia, 1) "D_UR + miesiac", add_months(data_urodzenia, -3) "D_UR - 3 miesiace"
from pracownicy;

/* Zadanie 12 */
select sysdate TERAZ, sysdate + 1/24 "GODZINE POZNIEJ", sysdate - 5/24 "PIEC GODZIN WCZESNIEJ"
from dual;

/* Zadanie 13 */
alter session set nls_date_format='YYYY/MM/DD';

/* Zadanie 14 */
select next_day(to_date('2021/04/05', 'YYYY/MM/DD'), 'thursday') "NASTEPNY CZWARTEK"
from dual;

/* Zadanie 15 */
select to_char(last_day(to_date('02/2022', 'MM/YYYY')), 'DD MON YYYY') "ostatni dzien lutego 2022"
from dual;

/* Zadanie 16 */
select imie, nazwisko
from pracownicy
where to_char(data_urodzenia, 'D') = '2'
and lower(imie) like '%a';

/* Zadanie 17 */
select nazwisko, translate(nazwisko, 'LA', '*?') "NAZWISKO PO ZAMIANIE"
from pracownicy;

/* Zadanie 18 */
select nazwisko, replace(nazwisko, 'ZYK', 'SKI') "NAZWISKO PO ZAMIANIE"
FROM pracownicy;

/* Zadanie 19 */
select nazwisko
from pracownicy
where instr(nazwisko, 'B') != 0;

/* PD
od 17 do 23 bez 21 i 22 */

/* Zadanie 20 */
select upper(substr(nazwisko, 1, instr(lower(nazwisko), 'l') - 1) 
|| 'r' || substr(nazwisko, instr(lower(nazwisko), 'l') + 1)) nazwisko from pracownicy
where instr(lower(nazwisko), 'l') <> 0;

/* Zadanie 21 */
select imie, nazwisko, pensja, width_bucket(pensja, 0, 7000, 14) as kategoria
from pracownicy
order by kategoria desc;

/* Zadanie 22 */
select id_pracownika, case when pensja<2500 then 'Zbyt niska pensja'
                           when pensja>=2500 then to_char(pensja)
                           end informacja
from pracownicy;

select id_pracownika, decode(sign(pensja - 2500), -1, 'Zbyt niska pensja', to_char(pensja)) informacja
from pracownicy;

/* Zadanie 23 */
select initcap(imie) || ' ' || initcap(nazwisko) || ', ' || lower(zawod) 
|| ', ' || 'wiek: ' || trunc(months_between(sysdate, data_urodzenia) / 12) || '.' dane
from pracownicy
order by data_urodzenia asc;