# Write your MySQL query statement below
WITH temp AS (
    SELECT mr.user_id, COUNT(*) AS cnt
    FROM Movies AS m
    LEFT JOIN MovieRating AS mr 
    ON m.movie_id = mr.movie_id
    GROUP BY mr.user_id
),
temp1 AS (
    SELECT movie_id, AVG(rating) AS avg
    FROM MovieRating
    WHERE MONTH(created_at) = 2 AND YEAR(created_at) = 2020
    GROUP BY movie_id
)
(
    SELECT u.name AS results
    FROM temp AS t
    LEFT JOIN Users AS u 
    ON t.user_id = u.user_id
    ORDER BY t.cnt DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT m.title AS results
    FROM Movies AS m
    INNER JOIN temp1 t1 
    ON m.movie_id = t1.movie_id
    ORDER BY t1.avg DESC, m.title ASC
    LIMIT 1
);
