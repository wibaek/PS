-- 2025.03.07

with a_history as (
    select car_id, start_date
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where (start_date between '2022-08-01' and '2022-10-31')
        and car_id in (
            select car_id
            from CAR_RENTAL_COMPANY_RENTAL_HISTORY
            where start_date between '2022-08-01' and '2022-10-31'
            group by car_id
            having count(*) >= 5
        )
)
select month(start_date) as month, car_id, count(*) as records
from a_history
group by car_id, month(start_date)
order by month, car_id desc
