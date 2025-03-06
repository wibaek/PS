-- 2025.03.06

select floor(price/10000) * 10000 as price_group, count(floor(price/10000) * 10000 ) as products
from product
group by price_group
order by price_group;
