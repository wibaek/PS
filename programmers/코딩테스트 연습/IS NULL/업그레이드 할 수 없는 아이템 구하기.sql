-- 2025.03.06

select item_info.item_id as item_id, item_name, rarity
from item_info
where item_info.item_id not in (
    select parent_item_id from item_tree where parent_item_id is not null
)
order by item_info.item_id desc
