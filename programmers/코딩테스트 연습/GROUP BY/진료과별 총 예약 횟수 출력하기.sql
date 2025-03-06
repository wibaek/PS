-- 2025.03.06

select MCDP_CD as "진료과코드", count(MCDP_CD) as "5월예약건수"
from APPOINTMENT
where APNT_YMD between '2022-05-01 00:00:00' and '2022-05-31 23:59:59.999999'
-- where year(apnt_ymd) = '2022' and month(apnt_ymd) = '5'
group by MCDP_CD
order by count(MCDP_CD), MCDP_CD
