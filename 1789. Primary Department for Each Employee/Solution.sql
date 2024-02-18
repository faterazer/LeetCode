-- Write your PostgreSQL query statement below
WITH single_department_employee AS (
    SELECT  employee_id
    FROM    Employee
    GROUP BY employee_id
    HAVING  COUNT(department_id) = 1
)
SELECT  employee_id,
        department_id
FROM    Employee
WHERE   primary_flag = 'Y'
        OR employee_id IN (SELECT employee_id FROM single_department_employee)
