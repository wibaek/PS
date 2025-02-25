-- 2025.02.25

select id, name, host_id
from places
where host_id in (
    select host_id
    from places
    group by host_id
    having count(host_id) >= 2
);
