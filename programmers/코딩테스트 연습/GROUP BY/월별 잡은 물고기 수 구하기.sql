-- 2025.02.24

select 
    count(*) as fish_count,
    month(time) as month
from fish_info as f
group by month
order by month;
