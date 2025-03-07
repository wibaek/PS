-- 2025.03.07

select id, 
    case
    when percent_rank() over (order by size_of_colony desc) <= 0.25 then 'CRITICAL'
    when percent_rank() over (order by size_of_colony desc) <= 0.5 then 'HIGH'
    when percent_rank() over (order by size_of_colony desc) <= 0.75 then 'MEDIUM'
    when percent_rank() over (order by size_of_colony desc) <= 1.0 then 'LOW'
    end
    as colony_name
from ecoli_data
order by id
