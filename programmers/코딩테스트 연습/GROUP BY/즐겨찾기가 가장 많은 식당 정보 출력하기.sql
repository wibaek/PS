-- 2025.03.07

select ri.food_type as food_type, rest_id, rest_name, ri.favorites as favorites
from (select food_type, max(favorites) as fav
    from rest_info
    group by food_type
    ) as ag
join rest_info as ri on ag.food_type = ri.food_type and ag.fav = ri.favorites
order by food_type desc

-- join이 아닌 where 조건절에서 (ft, fv) in (ft, max(fv))로 하는 방식도 있다
