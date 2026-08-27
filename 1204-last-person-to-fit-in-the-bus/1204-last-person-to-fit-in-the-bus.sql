# Write your MySQL query statement below
WITH CummulativeSum AS(
    SELECT 
        person_name,
        SUM(weight) OVER(ORDER By turn) AS running_total
    FROM Queue
)
SELECT person_name
FROM CummulativeSum
WHERE running_total <= 1000
ORDER BY running_total DESC
LIMIT 1