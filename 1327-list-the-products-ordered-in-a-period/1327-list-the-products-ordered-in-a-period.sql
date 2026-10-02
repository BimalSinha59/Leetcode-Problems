# Write your MySQL query statement below
WITH Product_Units AS (
    SELECT p.product_name, SUM(o.unit) AS unit
    FROM Orders AS o
    LEFT JOIN Products AS p
    ON o.product_id = p.product_id AND (o.order_date >= '2020-02-01' AND o.order_date < '2020-03-01')
    GROUP BY p.product_name
)
SELECT product_name, unit
FROM Product_Units
WHERE product_name IS NOT NULL AND unit >= 100;