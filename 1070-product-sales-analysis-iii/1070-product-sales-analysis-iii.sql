# Write your MySQL query statement below
WITH FirstYears AS(
    SELECT product_id, MIN(year) AS first_year, quantity, price
    FROM Sales
    GROUP BY product_id
)
SELECT f.product_id, f.first_year, s.quantity, s.price
FROM FirstYears AS f
JOIN Sales AS s
ON f.product_id = s.product_id AND
   f.first_year = s.year