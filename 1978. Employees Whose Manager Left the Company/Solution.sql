-- Write your PostgreSQL query statement below
SELECT  employee_id
FROM    Employees
WHERE   salary < 30000
        AND manager_id IS NOT NULL
        AND NOT EXISTS (SELECT * FROM Employees AS e WHERE e.employee_id = Employees.manager_id)
ORDER BY employee_id;
