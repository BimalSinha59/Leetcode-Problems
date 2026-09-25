# Write your MySQL query statement below
WITH Salary_Rank AS(
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY d.name ORDER BY e.salary DESC) AS dense_rank_val
    FROM Employee AS e
    LEFT JOIN Department AS d
    ON e.departmentId = d.id
)
SELECT 
   Department,
   Employee,
   Salary  
FROM Salary_Rank
WHERE dense_rank_val <= 3;