-- 2025.02.24

select count(*) as fish_count
from fish_info as f
join fish_name_info as fn on f.fish_type = fn.fish_type
where fish_name = 'BASS' OR fish_name = 'SNAPPER';
