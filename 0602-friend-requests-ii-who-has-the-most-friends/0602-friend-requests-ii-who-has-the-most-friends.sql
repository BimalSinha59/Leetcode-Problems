# Write your MySQL query statement below
WITH Temp AS(
    SELECT requester_id AS id, COUNT(requester_id) AS cnt
    FROM RequestAccepted
    GROUP BY requester_id
    UNION ALL
    SELECT accepter_id, COUNT(accepter_id) AS cnt
    FROM RequestAccepted
    GROUP BY accepter_id
),
Sums AS(
    SELECT id, SUM(cnt) AS sum
    FROM Temp
    GROUP BY id
)
SELECT id, sum AS num
FROM Sums
WHERE sum = (SELECT MAX(sum) FROM Sums);
