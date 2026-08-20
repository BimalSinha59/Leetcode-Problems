# Write your MySQL query statement below
-- WITH CustomerFirstOrders AS (
--     SELECT
--         customer_id,
--         order_date,
--         customer_pref_delivery_date,
--         MIN(order_date) OVER (PARTITION BY customer_id) AS first_order_date
--     FROM Delivery
-- )
-- SELECT
--     ROUND(SUM(CASE WHEN order_date = first_order_date AND order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) / COUNT( DISTINCT customer_id) * 100, 2) AS immediate_percentage
-- FROM CustomerFirstOrders

-- //////// *********solution 2***********///// 

SELECT ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id
);