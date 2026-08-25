# Write your MySQL query statement below
WITH RankedPrices AS (
    SELECT 
        product_id, 
        new_price,
        -- Rank the dates in descending order for each product
        RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) as rnk
    FROM Products
    WHERE change_date <= '2019-08-16' -- Filter out future price changes
),
UniqueProducts AS (
    -- Get a unique list of all products in the table
    SELECT DISTINCT product_id FROM Products
)

SELECT 
    u.product_id,
    -- If a product has a price change history, take it; otherwise default to 10
    IFNULL(r.new_price, 10) AS price
FROM UniqueProducts u
LEFT JOIN RankedPrices r 
    ON u.product_id = r.product_id AND r.rnk = 1;
