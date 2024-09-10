# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) as count_no_trans
FROM Visits v
WHERE v.visit_id NOT IN(SELECT visit_id from Transactions)
GROUP BY v.customer_id;