-- 2025.03.07

select category, sum(sales) as total_sales
from book_sales as bs
join book as b on bs.book_id = b.book_id
where year(SALES_DATE) = 2022 and month(SALES_DATE) = 1
group by category
order by category
