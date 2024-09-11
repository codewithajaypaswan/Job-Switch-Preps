# Write your MySQL query statement below
# either of JOIN will work
SELECT e1.name
FROM Employee e1, Employee e2
WHERE e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e1.id) >= 5

# SELECT e1.name
# FROM Employee e1 JOIN Employee e2
# ON e1.id = e2.managerId
# GROUP BY e1.id
# HAVING COUNT(e1.id) >= 5

# SELECT e1.name
# FROM Employee e1 LEFT JOIN Employee e2
# ON e1.id = e2.managerId
# GROUP BY e1.id
# HAVING COUNT(e1.id) >= 5

# SELECT e1.name
# FROM Employee e1 RIGHT JOIN Employee e2
# ON e1.id = e2.managerId
# GROUP BY e1.id
# HAVING COUNT(e1.id) >= 5