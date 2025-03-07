-- 2025.03.07

select a.id,
    (select count(id) from ecoli_data as b where b.parent_id = a.id) as child_count
from ecoli_data as a
order by id

-- join 해서 count(b.id)를 세는게 좋을 듯
