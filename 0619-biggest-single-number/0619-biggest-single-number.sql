# Write your MySQL query statement below
# SELECT MAX(num) as num
# FROM (SELECT num from MyNumbers GROUP BY num HAVING COUNT(num) = 1) as unique_number

SELECT MAX(num) as num
FROM MyNumbers
WHERE num IN(SELECT num from MyNumbers GROUP BY num HAVING COUNT(num) = 1);