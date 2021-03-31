create table OBIEKTY_KOMPLEKSU(
    id number(2) constraint id_PK primary key,
    symbol varchar(4) not null,
    nazwa varchar(30) not null,
    geometria sdo_geometry not null,
    constraint symbol_unique unique(symbol)
);

insert into OBIEKTY_KOMPLEKSU values(
                                     1,
                                     'L1',
                                     'LATARNIA',
                                    SDO_GEOMETRY(
                                        2001,
                                        NULL,
                                        SDO_POINT_TYPE(2,7, NULL),
                                        NULL,
                                        NULL)
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     2,
                                     'L2',
                                     'LATARNIA',
                                    SDO_GEOMETRY(
                                        2001,
                                        NULL,
                                        SDO_POINT_TYPE(2,2, NULL),
                                        NULL,
                                        NULL)
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     3,
                                     'L3',
                                     'LATARNIA',
                                    SDO_GEOMETRY(
                                        2001,
                                        NULL,
                                        SDO_POINT_TYPE(6,2, NULL),
                                        NULL,
                                        NULL)
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     4,
                                     'L4',
                                     'LATARNIA',
                                    SDO_GEOMETRY(
                                        2001,
                                        NULL,
                                        SDO_POINT_TYPE(6,7, NULL),
                                        NULL,
                                        NULL)
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     5,
                                     'L5',
                                     'LATARNIA',
                                    SDO_GEOMETRY(
                                        2001,
                                        NULL,
                                        SDO_POINT_TYPE(5,10, NULL),
                                        NULL,
                                        NULL)
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     6,
                                     'D1',
                                     'DROGA',
                                     SDO_GEOMETRY(
                                            2002,
                                            NULL,
                                            NULL,
                                            SDO_ELEM_INFO_ARRAY(1,2,1),
                                            SDO_ORDINATE_ARRAY(1, 11, 1, 1, 14, 1)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     7,
                                     'D2',
                                     'DROGA',
                                     SDO_GEOMETRY(
                                            2002,
                                            NULL,
                                            NULL,
                                            SDO_ELEM_INFO_ARRAY(1,2,1),
                                            SDO_ORDINATE_ARRAY(7, 1, 7, 9, 5, 9)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values (
                                      8,
                                      'B',
                                      'BOISKO',
                                      SDO_GEOMETRY(
                                          2003,
                                          NULL,
                                          NULL,
                                          SDO_ELEM_INFO_ARRAY(1, 1003, 3),
                                          SDO_ORDINATE_ARRAY(9,2, 13,5)
                                          )
                                     );

insert into OBIEKTY_KOMPLEKSU values(
                                     9,
                                     'HS',
                                     'HALA SPORTOWA',
                                     SDO_GEOMETRY(
                                         2003,
                                         NULL,
                                         NULL,
                                         SDO_ELEM_INFO_ARRAY(1, 1003, 4),
                                         SDO_ORDINATE_ARRAY(4,2, 6,4, 4,6)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     10,
                                     'T1',
                                     'TRYBUNA',
                                     SDO_GEOMETRY(
                                         2003,
                                         NULL,
                                         NULL,
                                         SDO_ELEM_INFO_ARRAY(1,1003,1),
                                         SDO_ORDINATE_ARRAY(8,7, 9,6, 13,6, 14,7, 8, 7)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     11,
                                     'T2',
                                     'TRYBUNA',
                                     SDO_GEOMETRY(
                                         2003,
                                         NULL,
                                         NULL,
                                         SDO_ELEM_INFO_ARRAY(1,1003,1),
                                         SDO_ORDINATE_ARRAY(14,5, 14,2, 15,1, 15,6, 14,5)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values(
                                     12,
                                     'A',
                                     'ADMINISTRACJA',
                                     sdo_geometry(
                                         2003,
                                         NULL,
                                         NULL,
                                         SDO_ELEM_INFO_ARRAY(1, 1003, 1, 11,2003,1),
                                         SDO_ORDINATE_ARRAY(2,11, 2,8, 4,8, 4,11, 2,11, 3.5,10, 3.5,9, 2.5,9, 3.5,10)
                                         )
                                    );

insert into OBIEKTY_KOMPLEKSU values (
                                      13, 'L', 'LODOWISKO',
                                      SDO_GEOMetry(
                                          2003,
                                          NULL,
                                          NULL,
                                          SDO_ELEM_INFO_ARRAY(1,1005,4, 1,2,1, 3,2,2, 7,2,1, 9,2,2),
                                          SDO_ORDINATE_ARRAY(11,10, 9,10, 8,9, 9,8, 11,8, 12,9, 11,10)
                                          )
                                     );

select id, w.geometria.ST_IsValid()
from OBIEKTY_KOMPLEKSU w
order by id;

commit;