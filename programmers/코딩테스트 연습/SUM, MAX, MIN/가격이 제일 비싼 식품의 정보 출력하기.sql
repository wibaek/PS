-- 2025.03.06

select *
from food_product
where price = (select max(price) from food_product)
