# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# way 1 ------>
# without making table
# delete p1 from Person p1, Person p2
# where p1.email = p2.email and p1.id > p2.id;

# way 2 ------>
# delete from Person
# where id not in(select id from (select min(id) as id, email from person group by email) i);

DELETE p1 from Person p1, Person p2
WHERE p1.email = p2.email AND p1.id > p2.id;