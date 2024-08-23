-- Write your PostgreSQL query statement below

SELECT Department.name AS Department,
       t.name AS Employee,
       salary AS Salary
FROM
  (SELECT name,
          salary,
          departmentId,
          DENSE_RANK() OVER (PARTITION BY departmentid
                             ORDER BY salary DESC) AS rank
   FROM Employee) AS t
JOIN Department ON t.departmentId = Department.id
WHERE rank <= 3
