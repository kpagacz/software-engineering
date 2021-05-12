/*
DROP TABLE czlonkowie_rodzin CASCADE CONSTRAINTS;
DROP TABLE osoby_na_utrzymaniu CASCADE CONSTRAINTS;
DROP TABLE pracownicy CASCADE CONSTRAINTS;
DROP TABLE oddzialy_firmy CASCADE CONSTRAINTS;
DROP SEQUENCE pracownicy_sekw;
*/

CREATE TABLE oddzialy_firmy
  (
    id    			NUMBER(2) CONSTRAINT oddzialy_firmy_PK PRIMARY KEY,
    nazwa 			VARCHAR2(40) NOT NULL,
    id_kierownika	NUMBER(5) CONSTRAINT oddzialy_firmy_kierow_U UNIQUE,
	CONSTRAINT oddzialy_firmy_CH CHECK (INITCAP(nazwa)=nazwa)
  );

CREATE TABLE pracownicy
  (
    id                NUMBER(5) CONSTRAINT pracownicy_PK PRIMARY KEY,
    pierwsze_imie     VARCHAR2 (15) NOT NULL,
    drugie_imie       VARCHAR2(15),
    nazwisko          VARCHAR2(25) NOT NULL,
    pesel             VARCHAR2(11) NOT NULL
	                     CONSTRAINT pracownicy_pesel_CH CHECK(length(pesel)=11)
	                     CONSTRAINT pracownicy_pesel_U UNIQUE,
    plec              CHAR(1) NOT NULL CONSTRAINT pracownicy_plec_CH CHECK ( plec IN ('K', 'M')),
    data_urodzenia    DATE NOT NULL,
    data_zatrudnienia DATE DEFAULT SYSDATE NOT NULL,
    id_oddzialu       NUMBER NOT NULL CONSTRAINT pracownicy_oddzialy_FK REFERENCES oddzialy_firmy(id),
	id_przelozonego   NUMBER(5) CONSTRAINT pracownicy_przelozony_FK REFERENCES pracownicy (id),
	CONSTRAINT pracownicy_daty_CH CHECK (data_zatrudnienia>data_urodzenia),
	CONSTRAINT pracownicy_nazwisko_CH CHECK (INITCAP(nazwisko)=nazwisko),
	CONSTRAINT pracownicy_p_imie_CH CHECK (INITCAP(pierwsze_imie)=pierwsze_imie),
	CONSTRAINT pracownicy_d_imie_CH CHECK (INITCAP(drugie_imie)=drugie_imie)
  );

ALTER TABLE oddzialy_firmy ADD CONSTRAINT oddzialy_firmy_pracownicy_FK FOREIGN KEY (id_kierownika) REFERENCES pracownicy(id) ;

CREATE TABLE CZLONKOWIE_RODZIN
  (
    pierwsze_imie         VARCHAR2 (15),
    plec                  CHAR (1) NOT NULL
	                      CONSTRAINT czlonkowie_rodzin_plec_CH CHECK (plec IN ('K', 'M')),
    data_urodzenia        DATE NOT NULL ,
    stopien_pokrewienstwa VARCHAR2 (30) NOT NULL,
	id_pracownika         NUMBER (5) CONSTRAINT czlonkowie_rodzin_prac_FK REFERENCES pracownicy(id),
	CONSTRAINT czlonkowie_rodzin_PK PRIMARY KEY (id_pracownika, pierwsze_imie),
	CONSTRAINT czlonkowie_rodzin_imie_CH CHECK (INITCAP(pierwsze_imie)=pierwsze_imie)
  );


CREATE INDEX pracownicy_NPI_IND on pracownicy(nazwisko, pierwsze_imie);

CREATE SEQUENCE pracownicy_SEKW
START WITH 1
INCREMENT BY 1;

INSERT INTO oddzialy_firmy VALUES (1, 'Oddział Lódź', NULL);
INSERT INTO oddzialy_firmy VALUES (2, 'Oddział Kraków', NULL);
INSERT INTO oddzialy_firmy VALUES (3, 'Oddział Lublin', NULL);

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Jan', 'Piotr', 'Nowak','67110512816', 'M', 	TO_DATE('05/11/1967','DD/MM/YYYY'), TO_DATE('01/01/2020','DD/MM/YYYY'),  1, NULL);

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Alicja', NULL, 'Tracz', '76071509449','K', TO_DATE('15/07/1976','DD/MM/YYYY'), TO_DATE('01/01/2020','DD/MM/YYYY'), 1, (SELECT id FROM pracownicy WHERE pesel= '67110512816'));

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Wojciech', 'Jakub', 'Sosnowski','58122478773','M', TO_DATE('24/12/1958','DD/MM/YYYY'), TO_DATE('01/01/2020','DD/MM/YYYY'),  2, (SELECT id FROM pracownicy WHERE pesel= '67110512816'));

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Jakub', NULL, 'Kot','78101908736', 'M', TO_DATE('19/10/1978','DD/MM/YYYY'), DEFAULT,  2, (SELECT id FROM pracownicy WHERE pesel= '58122478773'));

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Anna', 'Maria', 'Królak','68032723801', 'K', TO_DATE('27/03/1968','DD/MM/YYYY'), TO_DATE('01/02/2020','DD/MM/YYYY'),  3, (SELECT id FROM pracownicy WHERE pesel= '67110512816'));

INSERT INTO pracownicy VALUES(pracownicy_sekw.NEXTVAL, 'Mariola', 'Ewa', 'Zimnicka','74071335781', 'K', TO_DATE('13/07/1974','DD/MM/YYYY'), TO_DATE('01/02/2020','DD/MM/YYYY'), 3, (SELECT id FROM pracownicy WHERE pesel= '68032723801'));

INSERT INTO czlonkowie_rodzin VALUES('Zofia', 'K', TO_DATE('05/11/2009','DD/MM/YYYY'), 'córka',
(SELECT id FROM pracownicy WHERE pesel='74071335781'));

INSERT INTO czlonkowie_rodzin VALUES('Tomasz', 'M', TO_DATE('12/04/2011','DD/MM/YYYY'), 'syn',
(SELECT id FROM pracownicy WHERE pesel='74071335781'));

INSERT INTO czlonkowie_rodzin VALUES('Michalina', 'K', TO_DATE('05/11/2004','DD/MM/YYYY'), 'córka',
(SELECT id FROM pracownicy WHERE pesel='68032723801'));

COMMIT;

CREATE UNIQUE INDEX oddzialy_firmy_N_U_IND on oddzialy_firmy(nazwa);

UPDATE oddzialy_firmy
SET id_kierownika=(SELECT id FROM pracownicy WHERE pesel='67110512816')
WHERE id=1;

UPDATE oddzialy_firmy
SET id_kierownika=(SELECT id FROM pracownicy WHERE pesel='58122478773')
WHERE id=2;

UPDATE oddzialy_firmy
SET id_kierownika=(SELECT id FROM pracownicy WHERE pesel='68032723801')
WHERE id=3;

COMMIT;

ALTER TABLE oddzialy_firmy MODIFY id_kierownika NOT NULL;

ALTER TABLE czlonkowie_rodzin add CONSTRAINT czlonkowie_rodzin_CH CHECK ((stopien_pokrewienstwa='córka' AND plec='K') OR (stopien_pokrewienstwa='syn' AND plec='M') OR stopien_pokrewienstwa not in ('córka', 'syn'));

/*
INSERT INTO czlonkowie_rodzin VALUES('Marysia', 'M', TO_DATE('05/11/2004','DD/MM/YYYY'), 'córka',(SELECT id FROM pracownicy WHERE pesel='68032723801'));

INSERT INTO czlonkowie_rodzin VALUES('Marysia', 'K', TO_DATE('05/11/1969','DD/MM/YYYY'), 'żona',(SELECT id FROM pracownicy WHERE pesel='68032723801'));
*/

ALTER TABLE czlonkowie_rodzin DROP CONSTRAINT czlonkowie_rodzin_CH;

ALTER TABLE pracownicy MODIFY nazwisko VARCHAR2(40);

ALTER TABLE pracownicy MODIFY id_oddzialu DEFAULT 1;

RENAME czlonkowie_rodzin to osoby_na_utrzymaniu;
ALTER TABLE osoby_na_utrzymaniu RENAME CONSTRAINT czlonkowie_rodzin_PK TO osoby_na_utrzymaniu_PK;
ALTER TABLE osoby_na_utrzymaniu RENAME CONSTRAINT czlonkowie_rodzin_plec_CH TO osoby_na_utrzymaniu_plec_CH;
ALTER TABLE osoby_na_utrzymaniu RENAME CONSTRAINT czlonkowie_rodzin_imie_CH TO osoby_na_utrzymaniu_imie_CH;
ALTER TABLE osoby_na_utrzymaniu RENAME CONSTRAINT czlonkowie_rodzin_prac_FK TO osoby_na_utrzymaniu__prac_FK;


-- ALTER SESSION SET NLS_DATE_FORMAT='DD MON YYYY';
-------------------------------------------------------------------
SELECT * FROM pracownicy;
SELECT * FROM oddzialy_firmy;
SELECT * FROM osoby_na_utrzymaniu;


/* Part 1 a) */
create view v_pracownicy as (
select pierwsze_imie || ' ' || drugie_imie dane, case when plec='K' then 'Kobieta'
                                                    when plec='M' then 'Mezczyzna' end plec
from pracownicy
                            );

select text, TEXT_LENGTH from user_views where VIEW_NAME='V_PRACOWNICY';

insert into v_pracownicy values('Konrad Pagacz', 'Mezczyzna'); /* nie można! */

/* Part 1 b) */
create view v_pracownicy_dane as (
select id, pierwsze_imie, nazwisko, pesel, plec, data_urodzenia, id_oddzialu
from pracownicy
                                 );

insert into v_pracownicy_dane values(55, 'Roman', 'Nowak', '77091956714', 'M', to_date('19/09/1977', 'DD/MM/YYYY'), 2);
select * from v_pracownicy_dane;
update v_pracownicy_dane set pierwsze_imie='Robert' where id=55;
select * from v_pracownicy_dane;
delete v_pracownicy_dane where id = 55;
select * from v_pracownicy_dane;

select * from ALL_UPDATABLE_COLUMNS where TABLE_NAME='V_PRACOWNICY_DANE';

/* Part 1 c) */
create view v_pracownicy_liczba_osob as
    select id_oddzialu, count(id) "Liczba osób"
    from pracownicy
    group by id_oddzialu
    order by 1;
select * from
              v_pracownicy_liczba_osob;

select * from ALL_UPDATABLE_COLUMNS where TABLE_NAME='V_PRACOWNICY_LICZBA_OSOB';

/* Part 1 d) */
create view v_pracownicy_rozne_imiona as
    select distinct(pierwsze_imie)
    from pracownicy
    order by 1 asc;

select * from ALL_UPDATABLE_COLUMNS where TABLE_NAME='V_PRACOWNICY_ROZNE_IMIONA';
update v_pracownicy_rozne_imiona set pierwsze_imie='Alina' where pierwsze_imie='Alicja';

/* Part 2 Exc 1 */
-- DROP TABLE przedmioty;
-- DROP TABLE przedmioty_nowe;
CREATE TABLE przedmioty(
kod VARCHAR2(20) CONSTRAINT przedmioty_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
liczba_punktow_ECTS NUMBER);
CREATE TABLE przedmioty_nowe(
kod VARCHAR2(20) CONSTRAINT przedmioty_nowe_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
liczba_punktow_ECTS NUMBER);
INSERT INTO przedmioty VALUES('1100-PB0LII' , 'Podstawy baz danych', 6);
INSERT INTO przedmioty VALUES('1100-BP0LII', 'Projektowanie systemów bazodanowych', 6);
INSERT INTO przedmioty VALUES('1100-PZ0OII', 'Projekt zespołowy', 4);
INSERT INTO przedmioty VALUES('1100-UM0IWH', 'Wstęp do uczenia maszynowego', 5);
INSERT INTO przedmioty_nowe VALUES ('1100-MN0LII', 'Metody numeryczne', 5);
INSERT INTO przedmioty_nowe VALUES ('1100-APZPAD', 'Analiza portfelowa', 8);
INSERT INTO przedmioty_nowe VALUES ('1100-PZ0OII', 'Projekt zespołowy', 5);
COMMIT;
SELECT * FROM przedmioty ORDER BY kod;
SELECT * FROM przedmioty_nowe ORDER BY kod;

merge into przedmioty p1 using przedmioty_nowe p2
on(p1.kod=p2.kod)
when matched then
update set p1.liczba_punktow_ECTS = p2.liczba_punktow_ECTS
when not matched then
insert (p1.kod, p1.nazwa, p1.liczba_punktow_ECTS) values ( p2.kod, p2.nazwa, p2.liczba_punktow_ECTS );

select * from przedmioty;
commit;

/* Part 2 Exc 2 */
DROP TABLE osoby;
CREATE TABLE osoby(
id NUMBER CONSTRAINT osoby_PK PRIMARY KEY,
imie VARCHAR2(20) NOT NULL,
nazwisko VARCHAR2(50) NOT NULL,
data_urodzenia DATE NOT NULL,
e_mail VARCHAR2(30));
INSERT INTO osoby VALUES(1, 'JAN', 'MICHALAK', TO_DATE('15/04/1994', 'DD/MM/YYYY'), NULL);
INSERT INTO osoby VALUES(2, 'ANNA', 'MICHALAK', TO_DATE('05/12/1990', 'DD/MM/YYYY'),
'anna_michalak@o2.pl');
INSERT INTO osoby VALUES(3, 'EWA', 'ZATORSKA', TO_DATE('04/07/1980', 'DD/MM/YYYY'), NULL);
INSERT INTO osoby VALUES(4, 'JAN', 'KOWALSKI', TO_DATE('19/11/1983', 'DD/MM/YYYY'), NULL);
COMMIT;
SELECT * FROM osoby ORDER BY id;

merge into osoby o1 using
(select id, lower(substr(nazwisko, 1, 2)) || lower(substr(imie, 1, 3)) || to_char(data_urodzenia, 'YYYY') || '@' || 'uni.pl' email
from osoby where e_mail is null) o2
on (o1.id=o2.id)
when matched then
update set o1.e_mail=o2.email;

select * from osoby;
commit;

/* Part 2 Exc 3 */
DROP TABLE ubrania;
DROP TABLE ubrania_nowe;
DROP SEQUENCE ubrania_sekw;
DROP SEQUENCE ubrania_nowe_sekw;
CREATE TABLE ubrania(
id NUMBER CONSTRAINT ubrania_PK PRIMARY KEY,
kod VARCHAR2(20) NOT NULL CONSTRAINT ubrania_kod_U UNIQUE,
nazwa VARCHAR2(50) NOT NULL,
opis VARCHAR2(500),
typ VARCHAR2(20) NOT NULL CONSTRAINT ubrania_typ_CH CHECK (typ IN ('Kobieta', 'Mężczyzna',
'Dziewczynka', 'Chłopiec')),
cena NUMBER NOT NULL,
kolekcja VARCHAR2(30) NOT NULL);
CREATE SEQUENCE ubrania_sekw START WITH 1 INCREMENT BY 1;
INSERT INTO ubrania VALUES(ubrania_sekw.NEXTVAL, 'PK-021', 'Pikowana kurtka z połyskującego
materiału', NULL, 'Kobieta', 219.50, 'JESIEŃ-ZIMA 2019');
INSERT INTO ubrania VALUES(ubrania_sekw.NEXTVAL, 'P-028', 'Długi ocieplany płaszcz', NULL,
'Kobieta', 239.70, 'JESIEŃ-ZIMA 2020');
INSERT INTO ubrania VALUES(ubrania_sekw.NEXTVAL, 'KP-051', 'Kurtka puchowa', NULL, 'Mężczyzna',
799.55, 'JESIEŃ-ZIMA 2020');
INSERT INTO ubrania VALUES(ubrania_sekw.NEXTVAL, 'B-041', 'Bluza gładka z kapturem', NULL,
'Mężczyzna', 99.50, 'JESIEŃ-ZIMA 2020');
INSERT INTO ubrania VALUES(ubrania_sekw.NEXTVAL, 'SW-051', 'Sweterek z Myszką Miki', NULL,
'Dziewczynka', 39.00, 'JESIEŃ-ZIMA 2020');
CREATE TABLE ubrania_nowe(
id NUMBER CONSTRAINT ubrania_nowe_PK PRIMARY KEY,
kod VARCHAR2(20) NOT NULL CONSTRAINT ubrania_nowe_kod_U UNIQUE,
nazwa VARCHAR2(50) NOT NULL,
opis VARCHAR2(500),
typ VARCHAR2(20) NOT NULL CHECK (typ IN ('Kobieta', 'Mężczyzna', 'Dziewczynka', 'Chłopiec')),
cena NUMBER NOT NULL);
CREATE SEQUENCE ubrania_nowe_sekw START WITH 1 INCREMENT BY 1;
INSERT INTO ubrania_nowe VALUES(ubrania_nowe_sekw.NEXTVAL, 'SP-121', 'Kloszowa spódnica z tiulu',
NULL, 'Kobieta', 279.50);
INSERT INTO ubrania_nowe VALUES(ubrania_nowe_sekw.NEXTVAL, 'K-125', 'Kurtka dżinsowa', NULL,
'Mężczyzna', 149.99);
INSERT INTO ubrania_nowe VALUES(ubrania_nowe_sekw.NEXTVAL, 'SP-153', 'Plisowana spódnica', NULL,
'Kobieta', 133.99);
COMMIT;
SELECT * FROM ubrania ORDER BY id;
SELECT * FROM ubrania_nowe ORDER BY id;

merge into ubrania u1
    using ((select ubrania_nowe.*, 'WIOSNA-LATO-2021' kolekcja from ubrania_nowe) union (select * from ubrania where kolekcja='JESIEŃ-ZIMA 2020')) u2
on (u1.kod = u2.kod)
when not matched then insert (u1.id, u1.kod, u1.nazwa, u1.opis, u1.typ, u1.cena, u1.kolekcja) values(
    ubrania_sekw.nextval, u2.kod, u2.nazwa, u2.opis, u2.typ, u2.cena, u2.kolekcja
)
when matched then update set u1.cena=0.85 * u2.cena;

select * from ubrania;

/* Part 2 exc 4 */
DROP TABLE ubezpieczeni;
DROP SEQUENCE ubezpieczeni_sekw;
CREATE TABLE ubezpieczeni
(
 id NUMBER(5) CONSTRAINT ubezpieczeni_PK PRIMARY KEY,
 nazwisko VARCHAR2(25) NOT NULL,
 imie VARCHAR2(15) NOT NULL,
 pesel VARCHAR2(11) NOT NULL,
 data_urodzenia DATE NOT NULL,
 numer_ubezpieczenia VARCHAR2(20) CONSTRAINT ubezpieczeni_numer_U UNIQUE,
 kwota_ubezpieczenia NUMBER NOT NULL
);

CREATE SEQUENCE ubezpieczeni_sekw
START WITH 1
INCREMENT BY 1;
INSERT INTO ubezpieczeni VALUES(ubezpieczeni_sekw.NEXTVAL, 'Nowak', 'Jan',
'67110512816',TO_DATE('05/11/1967','DD/MM/YYYY'),'2021/1', 20000);
INSERT INTO ubezpieczeni VALUES(ubezpieczeni_sekw.NEXTVAL, 'Tracz', 'Alicja', '76071509449',
TO_DATE('15/07/1976','DD/MM/YYYY'), '2021/2', 10000);
INSERT INTO ubezpieczeni VALUES(ubezpieczeni_sekw.NEXTVAL, 'Sosnowski', 'Wojciech',
'58122478773', TO_DATE('24/12/1958','DD/MM/YYYY'), '2021/3', 10000);
COMMIT;

SELECT * FROM pracownicy ORDER BY id;
SELECT * FROM ubezpieczeni ORDER BY id;
select ubezpieczeni_sekw.nextval from dual;
select ubezpieczeni_sekw.currval from dual;
select to_char(ubezpieczeni_sekw.currval) from dual;

merge into ubezpieczeni u using pracownicy p on (p.id=u.id)
when matched then update set u.kwota_ubezpieczenia=3*u.kwota_ubezpieczenia
when not matched then insert (u.id, u.nazwisko, u.imie, u.pesel, u.data_urodzenia, u.numer_ubezpieczenia, u.kwota_ubezpieczenia) values(
                                                                                                                                        ubezpieczeni_sekw.nextval,
                                                                                                                                        p.pierwsze_imie,
                                                                                                                                        p.nazwisko,
                                                                                                                                        p.pesel,
                                                                                                                                        p.data_urodzenia,
                                                                                                                                        '2021/'||ubezpieczeni_sekw.nextval,
                                                                                                                                        10000
                                                                                                                                       );
select * from pracownicy;
select * from ubezpieczeni;

/* Part 2 exc 5 */
-- DROP TABLE zuzycie_ostatni_okres;
-- DROP TABLE odczyty;
-- DROP TABLE liczniki;
-- DROP SEQUENCE odczyty_sekw;
CREATE TABLE liczniki(
numer VARCHAR2(20) CONSTRAINT liczniki_PK PRIMARY KEY,
data_zalozenia DATE NOT NULL,
id_klienta NUMBER NOT NULL);
CREATE TABLE odczyty(
id NUMBER CONSTRAINT odczyty_PK PRIMARY KEY,
id_pracownika NUMBER(2) NOT NULL,
numer_licznika VARCHAR2(20) NOT NULL CONSTRAINT odczyty_liczniki_FK REFERENCES liczniki(numer),
stan NUMBER NOT NULL,
data DATE NOT NULL,
uwagi VARCHAR2(200) NULL);
CREATE TABLE zuzycie_ostatni_okres(
numer_licznika VARCHAR2(20) NOT NULL CONSTRAINT zuzycie_ostatni_okres_PK PRIMARY KEY CONSTRAINT
zuzycie_liczniki_FK REFERENCES liczniki(numer),
data_od date NOT NULL,
data_do date NOT NULL,
stan_od NUMBER NOT NULL,
stan_do NUMBER NOT NULL,
CONSTRAINT zuzycie_daty_CH CHECK (data_od<data_do),
CONSTRAINT zuzycie_stan_CH CHECK (stan_od<=stan_do));
INSERT INTO liczniki VALUES ('01863-54653456-11-0', TO_DATE('13/04/2019', 'DD/MM/YYYY'), 1);
INSERT INTO liczniki VALUES ('01763-54983456-12-1', TO_DATE('01/06/2019', 'DD/MM/YYYY'), 2);
INSERT INTO liczniki VALUES ('01963-59853456-01-2', TO_DATE('15/01/2020', 'DD/MM/YYYY'), 5);
INSERT INTO liczniki VALUES ('02863-54653458-07-3', TO_DATE('17/11/2020', 'DD/MM/YYYY'), 7);
COMMIT;
SELECT * FROM liczniki;
CREATE SEQUENCE odczyty_sekw START WITH 1 INCREMENT BY 1;
-- CREATE SEQUENCE odczyty_sekw START WITH 0 INCREMENT BY 1 MINVALUE 0; -- w EE
-- odczyty wykonane w lipcu 2019 roku
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 3, '01863-54653456-11-0', 364.3,
TO_DATE('05/07/2019', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 3, '01763-54983456-12-1', 200.9,
TO_DATE('05/07/2019', 'DD/MM/YYYY'), NULL);
-- odczyty wykonane w styczniu 2020 roku
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 4, '01863-54653456-11-0', 1456.4,
TO_DATE('05/01/2020', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 5, '01763-54983456-12-1', 1100.8,
TO_DATE('06/01/2020', 'DD/MM/YYYY'), NULL);
-- odczyty wykonane w lipcu 2020 roku
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 3, '01863-54653456-11-0', 2640.9,
TO_DATE('03/07/2020', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 5, '01763-54983456-12-1', 2100.9,
TO_DATE('06/07/2020', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 5, '01963-59853456-01-2',1106.1,TO_DATE('06/07/2020', 'DD/MM/YYYY'), NULL);
-- odczyty wykonane w styczniu 2021 roku
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 4, '01863-54653456-11-0', 3648.9,
TO_DATE('07/01/2021', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 4, '01763-54983456-12-1',
3400.2,TO_DATE('07/01/2021', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 4, '01963-59853456-01-2', 2186.1,
TO_DATE('07/01/2021', 'DD/MM/YYYY'), NULL);
INSERT INTO odczyty VALUES (odczyty_sekw.NEXTVAL, 4, '02863-54653458-07-3', 386.1,
TO_DATE('08/01/2021', 'DD/MM/YYYY'), NULL);
COMMIT;
SELECT * FROM odczyty;
-- stan za okres styczeń 2020 - lipiec 2020
INSERT INTO zuzycie_ostatni_okres VALUES ('01863-54653456-11-0', TO_DATE('05/01/2020',
'DD/MM/YYYY'), TO_DATE('03/07/2020', 'DD/MM/YYYY'), 1456.4, 2640.9);
INSERT INTO zuzycie_ostatni_okres VALUES ('01763-54983456-12-1', TO_DATE('06/01/2020',
'DD/MM/YYYY'), TO_DATE('06/07/2020', 'DD/MM/YYYY'), 1100.8, 2100.9);
-- tu rozpoczęciem okresu jest data założenia licznika
INSERT INTO zuzycie_ostatni_okres VALUES ('01963-59853456-01-2', TO_DATE('15/01/2020',
'DD/MM/YYYY'), TO_DATE('06/07/2020', 'DD/MM/YYYY'), 0, 1106.1);
COMMIT;
SELECT * FROM zuzycie_ostatni_okres;
