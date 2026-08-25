# Write your MySQL query statement below
WITH PrevnNexts AS(
    SELECT *,
    LEAD(num, 1) OVER(ORDER BY id) AS next_num,
    LAG(num, 1) OVER(ORDER By id) AS prev_num
    FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums
FROM PrevnNexts
WHERE prev_num = num AND next_num = num