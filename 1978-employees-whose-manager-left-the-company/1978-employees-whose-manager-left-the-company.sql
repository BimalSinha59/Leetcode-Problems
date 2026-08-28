# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees AS e
LEFT JOIN Employees AS m
ON e.manager_id = m.employee_id
WHERE e.salary < 30000 AND m.employee_id IS NULL AND e.manager_id IS NOT NULL
ORDER BY e.employee_id;