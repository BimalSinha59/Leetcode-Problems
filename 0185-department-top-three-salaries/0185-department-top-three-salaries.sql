# Write your MySQL query statement below
WITH Salary_Rank AS(
    SELECT 
        d.name AS department_name,
        e.name AS employee_name,
        e.salary AS emp_salary,
        DENSE_RANK() OVER (PARTITION BY d.name ORDER BY e.salary DESC) AS dense_rank_val
    FROM Employee AS e
    LEFT JOIN Department AS d
    ON e.departmentId = d.id
)
SELECT 
   department_name AS Department,
   employee_name AS Employee,
   emp_salary AS Salary  
FROM Salary_Rank
WHERE dense_rank_val <= 3;