# Write your MySQL query statement below
-- SELECT MAX(salary) AS SecondHighestSalary
-- FROM Employee
-- WHERE salary < (SELECT MAX(salary) FROM Employee);

WITH Salary_Rank AS(
    SELECT 
        salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) dense_rnk
    FROM Employee
)
SELECT MAX(salary) AS SecondHighestSalary
FROM Salary_Rank
WHERE dense_rnk = 2;