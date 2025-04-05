-- Write your PostgreSQL query statement below
SELECT
    employee_id
FROM
    Employees
WHERE NOT EXISTS (
    SELECT
        *
    FROM
        Salaries
    WHERE
        Salaries.employee_id = Employees.employee_id
)
UNION
SELECT
    employee_id
FROM
    Salaries
WHERE NOT EXISTS (
    SELECT
        *
    FROM
        Employees
    WHERE
        Employees.employee_id = Salaries.employee_id
)
ORDER BY
    employee_id;
