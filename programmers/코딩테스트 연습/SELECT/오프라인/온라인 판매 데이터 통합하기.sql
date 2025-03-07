-- 2025.03.07

select date_format(sales_date, '%Y-%m-%d') as sales_date, product_id, user_id, sales_amount
from (
    (
    select sales_date, product_id, user_id, sales_amount
    from online_sale
    )
    union
    (
    select sales_date, product_id, null as user_id, sales_amount
    from offline_sale
    )
) as sale
where month(sales_date) = 3 and year(sales_date) = 2022
order by sales_date, product_id, user_id
