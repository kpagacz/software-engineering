/* a) */
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

    pierwsze_imie varchar(15) constraint prac_pierwsze_imie_nn not null,

    drugie_imie varchar(15),

    nazwisko varchar(25) constraint prac_nazwisko_nn not null,

    pesel varchar(11) constraint prac_pesel_nn not null,
    constraint prac_pesel_unique unique(pesel),

    plec char(1) constraint prac_plec_nn not null,

    data_urodzenia date constraint prac_data_urodzenia_nn not null,

    data_zatrudnienia date default sysdate constraint prac_data_zatrudnienia_nn not null,

    id_oddzialu number(2),

    id_przelozonego number(3),
    constraint prac_id_przelozonego_fk foreign key(id_przelozonego) references pracownicy(id),
    constraint prac_pierwsze_imie_check check(regexp_like(pierwsze_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint prac_drugie_imie_check check(regexp_like(drugie_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint prac_nazwisko_check check(regexp_like(nazwisko, '^[[:upper:]][[:lower:]]*$')),
    constraint prac_plec_check check(plec like 'K' or plec like 'M'),
    constraint prac_pesel_check check(length(pesel) = 11),
    constraint prac_dates_check check(data_zatrudnienia > data_urodzenia)
);

create table czlonkowie_rodzin(
    pierwsze_imie varchar(15),

    plec char(1) constraint czr_plec_nn not null,

    data_urodzenia date,

    stopien_pokrewienstwa varchar(30) constraint czr_stopien_pokrewienstwa_nn not null,

    id_pracownika number(3),
    constraint czr_id_pracownika_fk foreign key(id_pracownika) references pracownicy(id),
    constraint czr_pk primary key(pierwsze_imie, id_pracownika),
    constraint czr_pierwsze_imie_check check(regexp_like(pierwsze_imie, '^[[:upper:]][[:lower:]]*$')),
    constraint czr_plec_check check(plec like 'K' or plec like 'M')
);

alter table oddzialy_firmy add constraint of_id_kierownika_fk foreign key(id_kierownika) references pracownicy(id);
alter table pracownicy add constraint pracownicy_id_oddzialu_fk foreign key (id_oddzialu) references oddzialy_firmy(id);

commit work;

/* b) */
create index pracownicy_npi_ind on pracownicy(nazwisko, pierwsze_imie);

/* c) */
create sequence pracownicy_sekw increment by 1 start with 1;

/* d) */
insert into oddzialy_firmy values (
                                   1, 'Oddział Łódź', null
                                  );