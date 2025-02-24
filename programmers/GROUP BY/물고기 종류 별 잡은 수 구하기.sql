-- 2025.02.24

SELECT COUNT(*) AS FISH_COUNT, FISH_NAME
FROM FISH_INFO AS F
INNER JOIN FISH_NAME_INFO AS FN ON F.FISH_TYPE = FN.FISH_TYPE
GROUP BY FISH_NAME
ORDER BY FISH_COUNT DESC;
