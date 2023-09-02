CREATE TABLE hang (
    mahang INT,
    tenhang VARCHAR(50),
    nam DATE
);
drop table ngaygiao
CREATE TABLE ngaygiao (
    mahang INT,
    tenhang VARCHAR(50),
    ngaygiao NVARCHAR(50),
    ngaynhan NVARCHAR(50)
);

insert into ngaygiao values (123,'bao cao su','2023-07-30','2023-08-01')

insert into ngaygiao values (124,'sex toy','2023-07-30','2023-08-02')

insert into ngaygiao values (125,'gay nhu y','2023-07-30','2023-08-03')

select * from hang 
select * from ngaygiao


SHOW SCHEMAS;
SHOW DATABASES;
insert into hang values (123,'bao cao su','2002-09-03');
insert into hang values (124,'sextoy','2002-10-04');
insert into hang values (125,'gay nhu y','2002-09-03');