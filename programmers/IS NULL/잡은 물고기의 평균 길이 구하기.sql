-- 2025.02.20

SELECT ROUND(AVG(COALESCE(F.LENGTH, 10)), 2) AS AVERAGE_LENGTH
FROM FISH_INFO AS F;