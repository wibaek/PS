-- 2025.02.24

select
    id,
    fish_name,
    max_length as length
from fish_info as f
join fish_name_info as fn on f.fish_type = fn.fish_type
join (
    select fish_type, max(length) as max_length
    from fish_info
    group by fish_type
) as s on f.fish_type = s.fish_type and f.length = s.max_length
order by id;
