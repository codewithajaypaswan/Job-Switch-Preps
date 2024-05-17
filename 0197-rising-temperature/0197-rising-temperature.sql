# Write your MySQL query statement below
SELECT wt1.id
from Weather wt1, Weather wt2
WHERE wt1.temperature > wt2.temperature AND TO_DAYS(wt1.recordDate) - TO_DAYS(wt2.recordDate) = 1; 