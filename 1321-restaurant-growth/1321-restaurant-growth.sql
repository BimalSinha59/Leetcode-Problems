# Write your MySQL query statement below
WITH DailyTotals AS (
    -- Step 1: Combine multiple orders on the same day into a single daily sum
    SELECT 
        visited_on,
        SUM(amount) AS daily_amount
    FROM Customer
    GROUP BY visited_on
),
MovingMetrics AS (
    -- Step 2: Use window functions on the daily totals to look back 6 days
    SELECT 
        visited_on,
        SUM(daily_amount) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        ROUND(
            AVG(daily_amount) OVER (
                ORDER BY visited_on
                ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
            ), 2
        ) AS average_amount,
        -- Step 3: Track row order to find where the first 7-day window completes
        ROW_NUMBER() OVER (ORDER BY visited_on) AS row_num
    FROM DailyTotals
)
-- Step 4: Drop the first 6 rows because they do not have a full 7-day history
SELECT 
    visited_on,
    amount,
    average_amount
FROM MovingMetrics
WHERE row_num >= 7
ORDER BY visited_on ASC;
