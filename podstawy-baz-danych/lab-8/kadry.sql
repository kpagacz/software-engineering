drop table oceny;
drop table oceny_studentow;
drop table studenci;

CREATE TABLE studenci(
nr_studenta NUMBER CONSTRAINT stud_nr_PK PRIMARY KEY,
nazwisko VARCHAR(15) CONSTRAINT stud_naz_NN NOT NULL,
imie VARCHAR(15) CONSTRAINT stud_imie_NN NOT NULL,
data_ur DATE,
plec CHAR(1) CONSTRAINT stud_plec CHECK(plec='M' or plec='K')
);

CREATE TABLE oceny_studentow(
id_ocena NUMBER CONSTRAINT ocena_PK PRIMARY KEY,
nr_stud NUMBER,
data_oceny DATE CONSTRAINT data_oceny_NN NOT NULL,
ocena VARCHAR(15) CONSTRAINT ocena_oc_NN CHECK(ocena = '2' OR ocena = '3' OR ocena = '3.5' OR ocena = '4' OR ocena = '4.5' OR ocena = '5'),
slownie VARCHAR(15) CONSTRAINT slownie_NN CHECK(slownie='niedst' OR slownie = 'dost' OR slownie = 'dost+' OR
slownie = 'db' OR slownie = 'db+' OR slownie = 'bdb') NOT NULL,
CONSTRAINT oceny_studenci_FK FOREIGN KEY (nr_stud) REFERENCES studenci(nr_studenta));

ALTER TABLE oceny_studentow RENAME TO oceny;

ALTER TABLE studenci MODIFY(nazwisko VARCHAR2(30));

ALTER TABLE studenci ADD(telefon CHAR(7));

ALTER TABLE studenci DROP COLUMN telefon;

ALTER TABLE oceny MODIFY(ocena NOT NULL);

ALTER TABLE studenci MODIFY(plec CHAR(1) DEFAULT 'M');

/*
Zadanie 2. 
Wprowadzi? przyk?adowe rekordy do tabeli studenci:

nr_studenta	nazwisko	imie	data_ur	plec
1	Tkaczyk	Jerzy	15/10/1964	M
2	Krawczyk	Monika	19/05/1976	K
3	Matczyk	Maria	09/07/1978	K
4	Balcerek	Janusz	02/09/1962	M
 
oraz przyk?adowe dane do tabeli oceny
id_ocena	nr_stud	data_oceny	ocena	slownie
1	1	15/10/2014	5	bdb
2	2	19/10/2014	4.5	db+
3	2	19/10/2014	4	db
4	3	21/10/2014  3.5 dost+
*/

insert into studenci (nr_studenta, nazwisko, imie, data_ur, plec) values(1, 'Tkaczyk', 'Jerzy', TO_DATE('15.10.1964', 'dd.mm.yyyy'), 'M');
insert into studenci (nr_studenta, nazwisko, imie, data_ur, plec) values(2, 'Krawczyk', 'Monika', to_date('19.05.1976', 'dd.mm.yyyy'), 'K');
insert into studenci (nr_studenta, nazwisko, imie, data_ur, plec) values(3, 'Matczyk', 'Maria', to_date('09.07.1978', 'dd.mm.yyyy'), 'K');
insert into studenci (nr_studenta, nazwisko, imie, data_ur, plec) values(4, 'Balcerek', 'Janusz', to_date('02.09.1962', 'dd.mm.yyyy'), 'M');

insert into oceny values(1, 1, to_date('15/10/2014', 'dd/mm/yyyy'), 5, 'bdb');
insert into oceny values(2, 2, to_date('19/10/2014', 'dd/mm/yyyy'), 4.5, 'db+');
insert into oceny values(3, 2, to_date('19/10/2014', 'dd/mm/yyyy'), 4, 'db');
insert into oceny values(4, 3, to_date('21.10.2014', 'dd.mm.yyyy'), 3.5, 'dost+');

/*
Zadanie 3.. 
Okazuje si?, i? studentka o nr_studenta = 3 powinna nazywa? si? Marczyk Marta, a nie Matczyk Maria jak b??dnie wprowadzono. Napisa? skrypt koryguj?cy te pomy?ki.
*/
update studenci
set 
imie = 'Marta',
nazwisko = 'Marczyk'
where nr_studenta = 3;

/*
Zadanie 4.
1. Wy??czy? ograniczenie dla pola plec. Po wy??czeniu ograniczenia sprawdzi? jego stan w s?owniku (ewentualnie mo?na skorzysta? w tym celu z SQL Developera).
2. Nast?pnie wprowadzi? do tabeli studenci jeden rekord z inn? warto?ci? w polu plec ni? ‘K’ lub ‘M’.
3. Po wprowadzeniu rekordu spróbowa? w??czy? ograniczenie dla pola plec uprzednio wy??czone.
*/
alter table studenci drop constraint stud_plec;
alter table studenci modify(plec CONSTRAINT stud_plec CHECK(plec='M' or plec='K'));
alter table studenci disable constraint stud_plec;

insert into studenci values(5, 'Nowak', 'Maria', to_date('25/10/1968', 'dd.mm.yyyy'), 'A');

alter table studenci enable constraint stud_plec;

update studenci 
set plec = 'K'
where nr_studenta = 5;

alter table studenci enable constraint stud_plec;

/*
Zadanie 5.
Utworzy? sekwencje do wprowadzania warto?ci w polach nr_studenta oraz id_oceny w tabelach studenci i oceny. 
Sekwencja dla pola nr_studenta powinna wprowadza? kolejne liczby naturalne pocz?wszy od 1 i sko?czywszy na 9999,
natomiast dla pola id_oceny powinna wprowadza? kolejne liczby naturalne z krokiem 1 pocz?wszy od 1 do 99999.
*/
drop sequence nr_stud_seq;
drop sequence id_ocena_seq;

create sequence nr_stud_seq
start with 6
increment by 1
minvalue 1
maxvalue 9999
nocycle;

create sequence id_ocena_seq
start with 5
increment by 1
minvalue 1
maxvalue 99999
nocycle;

/*
Zadanie 6.
Wprowadzi? przyk?adowy rekord do tabeli studenci i przyk?adowy rekord do tabeli oceny z wykorzystaniem odpowiedniej sekwencji.
*/
insert into studenci (nr_studenta, nazwisko, imie, data_ur, plec) values(nr_stud_seq.NEXTVAL, 'Pagacz', 'Konrad', to_date('21/12/2020', 'dd/mm/yyyy'), 'M');
insert into oceny values(id_ocena_seq.nextval, nr_stud_seq.currval, to_date('21/12/2020', 'dd/mm/yyyy'), '5', 'bdb');
/*
Zadanie 7.
Utworzy? indeks o nazwie student na kolumnach nazwisko i imie w tabeli studenci ustawiony alfabetycznie. Po jego utworzeniu obejrze? indeks w s?owniku.
*/
create index student on studenci(nazwisko asc, imie asc);
select * from user_indexes;
/*
Zadanie 8.
Utworzy? tabel? studentki w ten sposób, aby zawiera?a wszystkie rekordy z tabeli studenci, które dotycz? studentek, tj. pole p?e? zawiera warto?? ‘K’. Zadanie rozwi?za? dwoma sposobami.
*/

CREATE TABLE studentki(
nr_studenta NUMBER CONSTRAINT studtki_nr_PK PRIMARY KEY,
nazwisko VARCHAR(15) CONSTRAINT studtki_naz_NN NOT NULL,
imie VARCHAR(15) CONSTRAINT studtki_imie_NN NOT NULL,
data_ur DATE,
plec CHAR(1) CONSTRAINT studtki_plec CHECK(plec='M' or plec='K')
);
ALTER TABLE studentki MODIFY(nazwisko VARCHAR2(30));
insert into studentki select * from studenci where plec = 'K' ;

create table studentki2 as select * from studenci where plec = 'K';

/*
Zadanie 9.
Podczas tworzenia tabeli oceny pomini?to pole ects z warto?ci? domy?ln? 0. Skorygowa? pomy?k?.
Punkty ects przyjmuj? warto?ci 0, 1,2,3,4,5,6. Skorygowa? w?asno?ci pola ects.
Skorygowa? warto?ci w tym polu dla wprowadzonych rekordów.
*/
alter table oceny
add ects number constraint oceny_ects_range check(ects >= 0 and ects <= 6);

update oceny
set ects = 2 where id_ocena = 1;

update oceny
set ects = 2 where id_ocena = 2;

update oceny
set ects = 2 where id_ocena = 3;

update oceny
set ects = 2 where id_ocena = 4;

update oceny
set ects = 2 where id_ocena = 5;