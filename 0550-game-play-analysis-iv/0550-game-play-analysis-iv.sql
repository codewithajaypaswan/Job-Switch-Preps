# Write your MySQL query statement below
SELECT
ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) from Activity), 2) AS fraction
FROM Activity
WHERE (player_id, DATE_SUB(event_date, Interval 1 DAY))
IN(SELECT player_id, min(event_date) from Activity GROUP BY player_id)