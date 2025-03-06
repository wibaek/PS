-- 2023.05.06

select sum(price) as TOTAL_PRICE
from item_info
where rarity = 'LEGEND';
