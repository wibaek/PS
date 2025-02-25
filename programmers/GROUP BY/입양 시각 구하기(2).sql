-- 2025.02.25

with recursive hours as (
    select 0 as hour
    union all
    select hour + 1 from hours where hour < 23
)
select hours.hour as hour, ifnull(count, 0) as count
from hours
left join (
    select hour(datetime) as hour, count(*) as count
    from animal_outs
    group by hour
) as ac on hours.hour = ac.hour
order by hours.hour;
