-- Write your PostgreSQL query statement below
SELECT  e1.employee_id AS employee_id,
        e1.name AS name,
        COUNT(*) AS reports_count,
        ROUND(AVG(e2.age), 0) AS average_age
FROM    Employees AS e1
JOIN    Employees AS e2
ON  e1.employee_id = e2.reports_to
GROUP BY    e1.employee_id, e1.name
ORDER BY    e1.employee_id;
