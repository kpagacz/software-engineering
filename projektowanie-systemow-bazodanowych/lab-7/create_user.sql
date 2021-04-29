CREATE TABLESPACE lab7tablespace
   DATAFILE 'tbs_lab7_data.dbf'
   SIZE 10M;

CREATE USER lab7
    IDENTIFIED BY lab7
    DEFAULT TABLESPACE lab7tablespace
    QUOTA 10M ON lab7tablespace
    QUOTA 5M ON system;

grant all privileges to lab7;