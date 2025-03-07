-- 2025.03.07

select ri.rest_id as REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, round(avg(rr.review_score), 2) as SCORE
from rest_info as ri
join rest_review as rr on ri.rest_id = rr.rest_id
where address like '서울%'
group by ri.rest_id
order by score desc, favorites desc

-- 예시에는 서울특별시만 적어놓고 정작 서울시로 시작하는 데이터가 있다. 흠
