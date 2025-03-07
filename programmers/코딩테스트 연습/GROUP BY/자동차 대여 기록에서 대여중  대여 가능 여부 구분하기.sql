-- 2025.03.07

select distinct car_id,
case when car_id not in (
            SELECT car_id 
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
            WHERE start_date <= '2022-10-16' 
              AND end_date >= '2022-10-16'
        )
        then '대여 가능'
        else '대여중'
        end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
order by car_id desc
