CREATE TABLESPACE lab9tablespace
   DATAFILE 'tbs_lab7_data.dbf'
   SIZE 10M;

CREATE USER lab9
    IDENTIFIED BY lab9
    DEFAULT TABLESPACE lab9tablespace
    QUOTA 10M ON lab9tablespace
    QUOTA 5M ON system;

grant all privileges to lab9;