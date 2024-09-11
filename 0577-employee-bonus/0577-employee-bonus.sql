# Write your MySQL query statement below
SELECT emp.name, bon.bonus
FROM Employee emp LEFT JOIN Bonus bon
ON emp.empId = bon.empId
WHERE bon.bonus IS NULL OR bon.bonus < 1000;