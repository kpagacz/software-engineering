create table oddzialy_firmy (
    id number(2),
    nazwa varchar(40) constraint oddzialy_firmy_nazwa_nn not null,
    id_kierownika number(3),
    constraint oddzialy_firmy_pk primary key(id),
    constraint oddzialy_firmy_nazwa_check check(regexp_like(nazwa, '^[[:upper:]][[:lower:]]*$'))
);

create table pracownicy (
    id number(3),
    constraint pracownicy_pk primary key(id),

    pierwsze_imie varchar(15) constraint pracownicy_pierwsze_imie_nn not null,

    drugie_imie varchar(15),

    nazwisko varchar(25) constraint pracownicy_nazwisko_nn not null,

    pesel varchar(11) constraint pracownicy_pesel_nn not null,
    constraint pracownicy_pesel_unique unique(pesel),

    plec char(1) constraint pracownicy_plec_nn not null,

    data_urodzenia date constraint pracownicy_data_urodzenia_nn not null,

    data_zatrudnienia date default sysdate constraint pracownicy_data_zatrudnienia_nn not null,

    id_oddzialu number(2),

    id_przelozonego number(3),
    constraint pracownicy_id_przelozonego_fk foreign key(id_przelozonego) references pracownicy(id),
    constraint pracownicy_pierwsze_imie_check check(regexp_like(pierwsze_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint pracownicy_drugie_imie_check check(regexp_like(drugie_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint pracownicy_nazwisko_check check(regexp_like(nazwisko, '^[[:upper:]][[:lower:]]*$')),
    constraint pracownicy_plec_check check(plec like 'K' or plec like 'M'),
    constraint pracownicy_pesel_check check(length(pesel) = 11),
    constraint pracownicy_dates_check check(data_zatrudnienia > pracownicy.data_urodzenia)
);

create table czlonkowie_rodzin(
    pierwsze_imie varchar(15),

    plec char(1) constraint czlonkowie_rodzin_plec_nn not null,

    data_urodzenia date,

    stopien_pokrewienstwa varchar(30) constraint czlonkowie_rodzin_stopien_pokrewienstwa_nn not null,

    id_pracownika number(3),
    constraint czlonkowie_rodzin_id_pracownika_fk foreign key(id_pracownika) references pracownicy(id),
    constraint czlonkowie_rodzin_pk primary key(pierwsze_imie, id_pracownika),
    constraint czlonkowie_rodzin_pierwsze_imie_check check(regexp_like(pierwsze_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint czlonkowie_rodzin_plec_check check(plec like 'K' or plec like 'M')
);

alter table oddzialy_firmy add constraint oddzialy_firmy_id_kierownika_fk foreign key(id_kierownika) references pracownicy(id);
alter table pracownicy add constraint pracownicy_id_oddzialu_fk foreign key (id_oddzialu) references oddzialy_firmy(id);

commit work;