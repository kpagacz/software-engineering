-- Skrypt utworzony na podstawie skryptu dr. J. Zyskowskiego
-- Usuwanie tabel: OSOBY, WYDZIALY, STANOWISKA, ZATRUDNIENIA, KIEROWNICY
/* DROP TABLE osoby CASCADE CONSTRAINTS;
DROP TABLE wydzialy CASCADE CONSTRAINTS;
DROP TABLE stanowiska CASCADE CONSTRAINTS;
DROP TABLE zatrudnienia CASCADE CONSTRAINTS;
DROP TABLE kierownicy CASCADE CONSTRAINTS;
*/
-- Tworzenie tabel: OSOBY, WYDZIALY, STANOWISKA, ZATRUDNIENIA, KIEROWNICY
CREATE TABLE Osoby (
id_os NUMBER(4) CONSTRAINT osoby_PK PRIMARY KEY,
nazwisko VARCHAR2(15) NOT NULL,
imie1 VARCHAR2(15) NOT NULL,
imie2 VARCHAR2(15),
d_ur DATE,
plec CHAR(1) NOT NULL CONSTRAINT osoby_plec_CH CHECK (plec='M' OR plec='K')
);
CREATE TABLE Wydzialy (
id_w NUMBER(4) CONSTRAINT wydzialy_PK PRIMARY KEY,
nazwa VARCHAR2(15) NOT NULL
);
CREATE TABLE Stanowiska (
id_s NUMBER(2) CONSTRAINT stanowiska_PK PRIMARY KEY,
nazwa VARCHAR2(10) NOT NULL CONSTRAINT stanowiska_nazwa_UN UNIQUE
);
CREATE TABLE Zatrudnienia (
id_z NUMBER(4) CONSTRAINT zatrudnienia_PK PRIMARY KEY,
id_os NUMBER(4) NOT NULL CONSTRAINT Osoby_Zatrudnienia REFERENCES Osoby (id_os),
od DATE NOT NULL,
do DATE,
id_w NUMBER(4) NOT NULL CONSTRAINT Wydzialy_Zatrudnienia REFERENCES Wydzialy (id_w),
pensja NUMBER(8) NOT NULL,
id_s NUMBER(2) NOT NULL CONSTRAINT Stanowiska_Zatrudnienia REFERENCES stanowiska
(id_s)
);
CREATE TABLE Kierownicy (
id_w NUMBER(4) CONSTRAINT Wydzialy_Kierownicy REFERENCES Wydzialy (id_w),
id_os NUMBER(4) NOT NULL CONSTRAINT Osoby_Kierownicy REFERENCES Osoby (id_os),
od DATE,
do DATE,
CONSTRAINT kierownicy_PK PRIMARY KEY (id_w, od)
);
-- Tworzenie indeksów
CREATE UNIQUE INDEX IDX_Wydzialy_nazwa ON Wydzialy (nazwa);
CREATE INDEX IDX_Zatrudnienia_id_os ON Zatrudnienia (id_os ASC);
CREATE INDEX IDX_Zatrudnienia_id_w ON Zatrudnienia (id_w ASC);
CREATE INDEX IDX_Zatrudnienia_id_s ON Zatrudnienia (id_s);
CREATE INDEX IDX_Kierownicy_id_w ON Kierownicy (id_w);
CREATE INDEX IDX_Kierownicy_id_os ON Kierownicy (id_os);
-- Wstawianie danych do tabeli OSOBY
INSERT INTO osoby VALUES
(1,'LIS','JAN',Null,TO_DATE('21/10/1978','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(2,'KOT','ADAM','MAREK',TO_DATE('21/11/1980','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(3,'NOREK','TADEUSZ',Null,TO_DATE('23/10/1982','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(4,'KRAWCZYK','ADAM',Null,TO_DATE('02/06/1982','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(5,'LIS','ANNA',Null,TO_DATE('23/12/1968','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(6,'KOWALSKA','EWA',Null,TO_DATE('11/05/1979','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(7,'NOWAK','MARIA','ANNA',TO_DATE('12/07/1979','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(8,'DUDA','BARBARA',Null,TO_DATE('20/12/1984','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(9,'KULA','KATARZYNA',Null,TO_DATE('12/11/1983','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(10,'MUREK','DANUTA',Null,TO_DATE('17/08/1975','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(11,'DUDEK','JAN',Null,TO_DATE('22/10/1948','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(12,'NOWAK','ADAM','MAREK',TO_DATE('11/11/1970','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(13,'KOREK','TADEUSZ',Null,TO_DATE('21/10/1978','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(14,'WOJTCZAK','ADAM',Null,TO_DATE('12/06/1985','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(15,'PIECHA','ANNA',Null,TO_DATE('25/11/1965','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(16,'SOCHA','EWA',Null,TO_DATE('13/07/1977','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(17,'TURECKA','MARIA','ANNA',TO_DATE('22/03/1979','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(18,'DYBA','BARBARA',Null,TO_DATE('22/05/1983','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(19,'WILK','KATARZYNA',Null,TO_DATE('16/11/1943','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(20,'GRZESIK','DANUTA',Null,TO_DATE('11/06/1976','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(21,'POLAK','JAN',Null,TO_DATE('22/10/1958','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(22,'CZECH','ADAM','MAREK',TO_DATE('11/04/1971','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(23,'KUNA','TADEUSZ',Null,TO_DATE('02/10/1953','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(24,'WANIEK','ADAM',Null,TO_DATE('12/06/1985','dd/mm/yyyy'),'M');
INSERT INTO osoby VALUES
(25,'PLICH','ANNA',Null,TO_DATE('21/10/1978','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(26,'SOWA','EWA',Null,TO_DATE('13/07/1957','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(27,'TUREK','MARIA','ANNA',TO_DATE('22/03/1949','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(28,'DROPS','BARBARA',Null,TO_DATE('22/05/1963','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(29,'WILGA','KATARZYNA',Null,TO_DATE('17/11/1953','dd/mm/yyyy'),'K');
INSERT INTO osoby VALUES
(30,'GOT','DANUTA',Null,TO_DATE('12/06/1946','dd/mm/yyyy'),'K');
COMMIT;
-- Wstawianie danych do tabeli STANOWISKA
INSERT INTO stanowiska VALUES (1,'asystent');
INSERT INTO stanowiska VALUES (2,'adiunkt');
INSERT INTO stanowiska VALUES (3,'profesor');
INSERT INTO stanowiska VALUES (4,'sekretarka');
COMMIT;
-- Wstawianie danych do tabeli WYDZIALY
INSERT INTO wydzialy VALUES (1,'MATEMATYKA');
INSERT INTO wydzialy VALUES (2,'FIZYKA');
INSERT INTO wydzialy VALUES (3,'PRAWO');
INSERT INTO wydzialy VALUES (4,'EKONOMIA');
INSERT INTO wydzialy VALUES (5,'FILOLOGIA');
INSERT INTO wydzialy VALUES (6,'BIOLOGIA');
COMMIT;
-- Wstawianie danych do tabeli ZATRUDNIENIA
INSERT INTO zatrudnienia VALUES
(1,1,TO_DATE('21/10/1998','dd/mm/yyyy'),TO_DATE('11/05/1999','dd/mm/yyyy'),1,1500,1);
INSERT INTO zatrudnienia VALUES
(2,2,TO_DATE('21/11/1999','dd/mm/yyyy'),TO_DATE('30/09/2005','dd/mm/yyyy'),1,1500,1);
INSERT INTO zatrudnienia VALUES
(3,2,TO_DATE('01/10/2005','dd/mm/yyyy'),NULL,5,2500,1);
INSERT INTO zatrudnienia VALUES
(4,3,TO_DATE('23/10/2002','dd/mm/yyyy'),NULL,1,1500,1);
INSERT INTO zatrudnienia VALUES
(5,4,TO_DATE('02/06/2004','dd/mm/yyyy'),NULL,1,1500,1);
INSERT INTO zatrudnienia VALUES
(6,5,TO_DATE('23/12/1988','dd/mm/yyyy'),NULL,1,4000,3);
INSERT INTO zatrudnienia VALUES
(7,6,TO_DATE('11/05/2001','dd/mm/yyyy'),NULL,2,1900,1);
INSERT INTO zatrudnienia VALUES
(8,7,TO_DATE('12/07/2002','dd/mm/yyyy'),NULL,2,1900,1);
INSERT INTO zatrudnienia VALUES
(9,8,TO_DATE('20/12/2003','dd/mm/yyyy'),NULL,2,2000,1);
INSERT INTO zatrudnienia VALUES
(10,9,TO_DATE('12/11/2004','dd/mm/yyyy'),NULL,2,2100,1);
INSERT INTO zatrudnienia VALUES
(11,10,TO_DATE('17/08/1995','dd/mm/yyyy'),TO_DATE('30/09/1999','dd/mm/yyyy'),2,1800,1);
INSERT INTO zatrudnienia VALUES
(12,10,TO_DATE('01/10/1999','dd/mm/yyyy'),NULL,2,2500,2);
INSERT INTO zatrudnienia VALUES
(13,11,TO_DATE('22/10/1988','dd/mm/yyyy'),TO_DATE('12/03/2002','dd/mm/yyyy'),2,1800,1);
INSERT INTO zatrudnienia VALUES
(14,12,TO_DATE('11/11/1990','dd/mm/yyyy'),TO_DATE('30/09/1996','dd/mm/yyyy'),2,1600,1);
INSERT INTO zatrudnienia VALUES
(15,12,TO_DATE('01/10/1996','dd/mm/yyyy'),TO_DATE('30/09/2002','dd/mm/yyyy'),2,2400,2);
INSERT INTO zatrudnienia VALUES (16,12,TO_DATE('01/10/2002','dd/mm/yyyy'),NULL,2,3400,3);
INSERT INTO zatrudnienia VALUES
(17,13,TO_DATE('21/10/1998','dd/mm/yyyy'),TO_DATE('30/09/2003','dd/mm/yyyy'),2,1750,1);
INSERT INTO zatrudnienia VALUES
(18,13,TO_DATE('01/10/2003','dd/mm/yyyy'),NULL,2,2750,2);
INSERT INTO zatrudnienia VALUES
(19,14,TO_DATE('12/06/2005','dd/mm/yyyy'),NULL,2,1900,1);
INSERT INTO zatrudnienia VALUES
(20,15,TO_DATE('25/11/1985','dd/mm/yyyy'),TO_DATE('20/10/1988','dd/mm/yyyy'),2,2600,2);
INSERT INTO zatrudnienia VALUES
(21,15,TO_DATE('21/10/1988','dd/mm/yyyy'),NULL,2,3600,3);
INSERT INTO zatrudnienia VALUES
(22,16,TO_DATE('13/07/1997','dd/mm/yyyy'),NULL,3,2500,2);
INSERT INTO zatrudnienia VALUES
(23,17,TO_DATE('22/03/1999','dd/mm/yyyy'),TO_DATE('26/04/2003','dd/mm/yyyy'),3,1900,1);
INSERT INTO zatrudnienia VALUES
(24,18,TO_DATE('22/05/2003','dd/mm/yyyy'),NULL,3,2000,1);
INSERT INTO zatrudnienia VALUES
(25,19,TO_DATE('16/11/1985','dd/mm/yyyy'),TO_DATE('16/11/1989','dd/mm/yyyy'),3,2600,3);
INSERT INTO zatrudnienia VALUES
(26,19,TO_DATE('17/11/1989','dd/mm/yyyy'),TO_DATE('15/11/1995','dd/mm/yyyy'),3,3600,3);
INSERT INTO zatrudnienia VALUES
(27,19,TO_DATE('16/11/1995','dd/mm/yyyy'),NULL,3,4500,3);
INSERT INTO zatrudnienia VALUES
(28,20,TO_DATE('11/06/1996','dd/mm/yyyy'),NULL,4,2000,2);
INSERT INTO zatrudnienia VALUES
(29,21,TO_DATE('02/10/1985','dd/mm/yyyy'),TO_DATE('30/09/2005','dd/mm/yyyy'),4,4000,3);
INSERT INTO zatrudnienia VALUES
(30,21,TO_DATE('01/10/2005','dd/mm/yyyy'),NULL,4,3600,3);
INSERT INTO zatrudnienia VALUES
(31,22,TO_DATE('11/04/1991','dd/mm/yyyy'),NULL,4,5000,3);
INSERT INTO zatrudnienia VALUES
(32,23,TO_DATE('02/10/1985','dd/mm/yyyy'),TO_DATE('01/10/1995','dd/mm/yyyy'),4,1300,1);
INSERT INTO zatrudnienia VALUES
(33,23,TO_DATE('02/10/1995','dd/mm/yyyy'),TO_DATE('30/09/2005','dd/mm/yyyy'),4,3300,2);
INSERT INTO zatrudnienia VALUES
(34,23,TO_DATE('01/10/2005','dd/mm/yyyy'),NULL,4,4300,3);
INSERT INTO zatrudnienia VALUES
(35,24,TO_DATE('12/06/2005','dd/mm/yyyy'),NULL,5,2100,1);
INSERT INTO zatrudnienia VALUES
(36,25,TO_DATE('21/10/1998','dd/mm/yyyy'),NULL,5,3000,2);
INSERT INTO zatrudnienia VALUES
(37,26,TO_DATE('13/07/1985','dd/mm/yyyy'),NULL,5,1400,1);
COMMIT;
-- Wstawianie danych do tabeli KIEROWNICY
INSERT INTO kierownicy VALUES (1,5,TO_DATE('23/12/1988','dd/mm/yyyy'),NULL);
INSERT INTO kierownicy VALUES (2,15,TO_DATE('25/11/1985','dd/mm/yyyy'),NULL);
INSERT INTO kierownicy VALUES (3,19,TO_DATE('16/11/1985','dd/mm/yyyy'),NULL);
INSERT INTO kierownicy VALUES
(4,21,TO_DATE('02/10/1985','dd/mm/yyyy'),TO_DATE('30/09/2005','dd/mm/yyyy'));
INSERT INTO kierownicy VALUES (4,23,TO_DATE('01/10/2005','dd/mm/yyyy'),NULL);
INSERT INTO kierownicy VALUES (5,26,TO_DATE('13/07/1985','dd/mm/yyyy'),NULL);
COMMIT;