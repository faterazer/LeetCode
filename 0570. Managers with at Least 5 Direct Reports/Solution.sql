-- Write your MySQL query statement below
SELECT  name
FROM    Employee
JOIN (
    SELECT  managerId
    FROM    Employee
    GROUP BY    managerId
    HAVING  COUNT(*) >= 5
) AS grouped
ON Employee.id = grouped.managerId
