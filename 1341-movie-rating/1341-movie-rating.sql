# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating AS mr 
JOIN Users AS u
ON mr.user_id = u.user_id
GROUP BY u.name
ORDER BY COUNT(*) DESC, u.name
LIMIT 1)

UNION ALL

(SELECT m.title AS results
FROM MovieRating AS mr 
JOIN Movies m
ON mr.movie_id = m.movie_id
WHERE MONTH(mr.created_at) = 2 AND YEAR(mr.created_at) = 2020
GROUP BY m.title
ORDER BY AVG(mr.rating) DESC, m.title
LIMIT 1);
