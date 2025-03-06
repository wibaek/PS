-- 2025.02.25

select hour(datetime) as hour, count(*) as count
from animal_outs
group by hour
having (9 <= hour) and (hour <= 19)
order by hour;
