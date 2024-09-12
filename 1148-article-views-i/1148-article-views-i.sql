# Write your MySQL query statement below

# SELECT author_id as id from Views
# WHERE author_id = viewer_id
# GROUP BY author_id
# ORDER BY author_id;

SELECT DISTINCT v1.author_id as id from Views v1, views v2
WHERE v1.author_id = v2.viewer_id AND v1.article_id = v2.article_id
ORDER BY v1.author_id;
