/* a) */
create table oddzialy_firmy (
    id number(2),
    nazwa varchar2(40) constraint of_nazwa_nn not null,
    id_kierownika number(3),
    constraint of_pk primary key(id),
    constraint of_nazwa_check check (nazwa = initcap(nazwa))
);

create table pracownicy (
    id number(3),
    constraint p_pk primary key(id),

    pierwsze_imie varchar2(15) constraint p_pierwsze_imie_nn not null,

    drugie_imie varchar2(15),

    nazwisko varchar2(25) constraint p_nazwisko_nn not null,

    pesel varchar2(11) constraint p_pesel_nn not null,
    constraint p_pesel_unique unique(pesel),

    plec char(1) constraint p_plec_nn not null,

    data_urodzenia date constraint p_data_urodzenia_nn not null,

    data_zatrudnienia date constraint p_data_zatrudnienia_nn not null,

    id_oddzialu number(2),

    id_przelozonego number(3),
    constraint p_id_przelozonego_fk foreign key(id_przelozonego) references pracownicy(id),
    constraint p_pierwsze_imie_check check ( pierwsze_imie = initcap(pierwsze_imie) ),
    constraint p_drugie_imie_check check ( drugie_imie = initcap(drugie_imie) ),
    constraint p_plec_check check(plec = 'K' or plec = 'M'),
    constraint p_pesel_check check (length(pesel) = 11),
    constraint p_data_uro_zatr_check check(data_urodzenia < data_zatrudnienia)
);

create table czlonkowie_rodzin(
    pierwsze_imie varchar2(15),

    plec char(1) constraint cr_plec_nn not null,

    data_urodzenia date,

    stopien_pokrewienstwa varchar2(30) constraint cr_stopien_pokrewienstwa_nn not null,

    id_pracownika number(3),
    constraint cr_id_pracownika_fk foreign key(id_pracownika) references pracownicy(id),
    constraint cr_pierwsze_imie_check check ( pierwsze_imie = initcap(pierwsze_imie) ),
    constraint cr_plec_check check(plec = 'K' or plec = 'M'),
    constraint cr_pk primary key(pierwsze_imie, id_pracownika)
);

alter table czlonkowie_rodzin
alter table oddzialy_firmy add constraint of_id_kierownika_fk foreign key(id_kierownika) references pracownicy(id);
alter table pracownicy add constraint p_id_oddzialu_fk foreign key (id_oddzialu) references oddzialy_firmy(id);
alter table pracownicy modify data_zatrudnienia default sysdate;

commit work;

/* b) */
create index pracownicy_npi_ind on pracownicy(nazwisko, pierwsze_imie);

select * from USER_INDEXES where index_name = 'PRACOWNICY_NPI_IND';

/* c) */
create sequence pracownicy_sekw start with 1 increment by 1;
select * from USER_SEQUENCES where SEQUENCE_NAME = 'PRACOWNICY_SEKW';

/* d) */
insert into oddzialy_firmy values(
                                  1,
                                  'Oddział Łódź',
                                  null
                                 );

insert into oddzialy_firmy values (
                                   2,
                                   'Oddział Kraków',
                                   null
                                  );
insert into oddzialy_firmy values (
                                   3,
                                   'Oddział Lublin',
                                   null
                                  );
select * from oddzialy_firmy;

begin
insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, data_urodzenia, data_zatrudnienia, plec, id_oddzialu)
 values (
         pracownicy_sekw.nextval,
         'Jan',
         'Piotr',
         'Nowak',
         '67110512816',
         to_date('05/11/1967', 'DD/MM/YYYY'),
         to_date('01/01/2020', 'DD/MM/YYYY'),
         'M',
         1
        );

insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, data_urodzenia, data_zatrudnienia, plec, id_oddzialu)
values (
        pracownicy_sekw.nextval,
        'Wojciech',
        'Jakub',
        'Sosnowski',
        '58122478773',
        to_date('24/12/1958', 'DD/MM/YYYY'),
        to_date('01/01/2020', 'DD/MM/YYYY'),
        'M',
        2
       );


insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, data_urodzenia, data_zatrudnienia, plec, id_oddzialu)
values (
        pracownicy_sekw.nextval,
        'Anna',
        'Maria',
        'Królak',
        '68032723801',
        to_date('27/03/1968', 'DD/MM/YYYY'),
        to_date('01/02/2020', 'DD/MM/YYYY'),
        'K',
        3
       );
    insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, data_urodzenia, data_zatrudnienia, plec, id_oddzialu, id_przelozonego)
values (
        pracownicy_sekw.nextval,
        'Alicja',
        null,
        'Tracz',
        '76071509449',
        to_date('15/07/1976', 'DD/MM/YYYY'),
        to_date('01/01/2020', 'DD/MM/YYYY'),
        'K',
        1,
        (select id from pracownicy where pesel = '67110512816')
       );
        insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, plec, data_urodzenia, data_zatrudnienia, id_oddzialu, id_przelozonego)
values (
        pracownicy_sekw.nextval,
        'Jakub',
        null,
        'Kot',
        '78101908736',
        'M',
        to_date('19/10/1978', 'DD/MM/YYYY'),
        sysdate,
        2,
        (select id from pracownicy where pesel = '58122478773')
       );

    insert into pracownicy (id, pierwsze_imie, drugie_imie, nazwisko, pesel, plec, data_urodzenia, data_zatrudnienia, id_oddzialu, id_przelozonego)
values (
        pracownicy_sekw.nextval,
        'Mariola',
        'Ewa',
        'Zimnicka',
        '74071335781',
        'K',
        to_date('13/07/1974', 'DD/MM/YYYY'),
        to_date('01/02/2020', 'DD/MM/YYYY'),
        3,
        (select id from pracownicy where pesel = '74071335781')
       );
commit;
end;

/* e) */
begin
    insert into czlonkowie_rodzin (pierwsze_imie, plec, data_urodzenia, stopien_pokrewienstwa, id_pracownika)
    values (
            'Zofia', 'K', to_date('05/11/2009', 'DD/MM/YYYY'), 'córka',
            (select id from pracownicy where pesel = '74071335781')
           );

    insert into czlonkowie_rodzin (pierwsze_imie, plec, data_urodzenia, stopien_pokrewienstwa, id_pracownika)
    values (
            'Tomasz', 'M', to_date('12/04/2011', 'DD/MM/YYYY'), 'syn',
            (select id from pracownicy where pesel = '74071335781')
           );

    insert into czlonkowie_rodzin (pierwsze_imie, plec, data_urodzenia, stopien_pokrewienstwa, id_pracownika)
    values (
            'Michalina', 'K', to_date('22/05/2004', 'DD/MM/YYYY'), 'córka',
            (select id from pracownicy where pesel = '68032723801')
           );
    commit;
end;

/* f) */
create unique index ODDZIALY_FIRMY_N_U_IND on oddzialy_firmy(nazwa);
select * from USER_INDEXES where INDEX_NAME = 'ODDZIALY_FIRMY_N_U_IND';

/* g) */
select * from V$NLS_PARAMETERS where PARAMETER in ('NLS_DATE_FORMAT', 'NLS_LANGUAGE', 'NLS_SORT', 'NLS_LENGTH_SEMANTICS');
alter session set NLS_DATE_FORMAT='DD MON YYYY';
select * from pracownicy;
select * from oddzialy_firmy;
select * from czlonkowie_rodzin;

/* h) */
begin
update oddzialy_firmy set id_kierownika = (select id from pracownicy where pesel = '67110512816') where id = 1;
update oddzialy_firmy set id_kierownika = (select id from pracownicy where pesel = '58122478773') where id = 2;
update oddzialy_firmy set id_kierownika = (select id from pracownicy where pesel = '68032723801') where id = 3;
    commit;
end;
select * from oddzialy_firmy;

/* i) */
alter table oddzialy_firmy modify id_kierownika not null;

/* j) */
alter table czlonkowie_rodzin
add constraint cr_plec_st_check check(case when stopien_pokrewienstwa='córka' then 'K'
    when stopien_pokrewienstwa='syn' then 'M'
    end = plec);
select * from USER_CONSTRAINTS where TABLE_NAME='CZLONKOWIE_RODZIN';

insert into czlonkowie_rodzin values('Marysia', 'M', TO_DATE('05/11/2004','DD/MM/YYYY'),
'córka',(select id from pracownicy where pesel='68032723801')); /* for some reason this does not work for me... */

select * from czlonkowie_rodzin;
delete from czlonkowie_rodzin where pierwsze_imie = 'Marysia';
alter table czlonkowie_rodzin drop constraint cr_plec_st_check;

/* k) */
alter session set NLS_LENGTH_SEMANTICS = 'CHAR';
alter table pracownicy modify nazwisko varchar2(40);

