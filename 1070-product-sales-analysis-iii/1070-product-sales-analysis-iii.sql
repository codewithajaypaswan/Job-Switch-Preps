# Write your MySQL query statement below
# SELECT product_id, year as first_year, quantity, price
# FROM Sales
# WHERE (product_id, year) IN(SELECT product_id, MIN(year) as year FROM Sales GROUP BY product_id);

SELECT s.product_id, s.year as first_year, s.quantity , s.price
FROM Sales s LEFT JOIN Product p
ON s.product_id = p.product_id
WHERE (s.product_id, s.year) IN(SELECT product_id, MIN(year) FROM Sales GROUP BY product_id)