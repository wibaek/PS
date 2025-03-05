-- 2025.03.06

with max_size (year, size) as (
    select year(differentiation_date), max(size_of_colony)
    from ecoli_data
    group by year(differentiation_date)
)
select year(differentiation_date) as year, (select size from max_size where year = year(e.differentiation_date)) - size_of_colony as year_dev, id
from ecoli_data as e
order by year, year_dev;
