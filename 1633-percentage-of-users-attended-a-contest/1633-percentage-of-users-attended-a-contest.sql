# Write your MySQL query statement below
SELECT contest_id, ROUND(COUNT(distinct user_id) * 100 / (SELECT COUNT(user_id) from users), 2) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;