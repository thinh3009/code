use hanghoa
-- query
select hang.mahang,hang.tenhang,hang.nam,ngaygiao.ngaygiao,ngaygiao.ngaynhan 
from hang  inner join ngaygiao 
on hang.mahang = ngaygiao.mahang

	
show tables from hanghoa;

alter table hang add CustomerName nvarchar(50)
alter table hang add phone int
alter table hang modify mahang bigint
alter table ngaygiao modify mahang bigint