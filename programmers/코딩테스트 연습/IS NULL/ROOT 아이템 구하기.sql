-- 2025.03.06

select item_info.item_id as item_id, item_name
from item_info
join item_tree on item_info.item_id = item_tree.item_id
where parent_item_id is null
