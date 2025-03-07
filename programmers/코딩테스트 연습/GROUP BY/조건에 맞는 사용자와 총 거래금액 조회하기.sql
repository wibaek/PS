-- 2025.03.07

select user_id, nickname, sum(price) as total_sales
from USED_GOODS_USER as u
join USED_GOODS_BOARD as b on u.user_id = b.writer_id
where status = 'DONE'
group by user_id, nickname
having sum(price) >= 700000
order by sum(price)
