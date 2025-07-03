-- Write your PostgreSQL query statement below
WITH RECURSIVE CTE AS (
    SELECT  employee_id,
            employee_name,
            manager_id,
            1 AS level,
            salary
    FROM    Employees
    WHERE   manager_id IS NULL
    UNION ALL
    SELECT  E.employee_id,
            E.employee_name,
            E.manager_id,
            C.level + 1,
            E.salary
    FROM    CTE AS C, Employees as E
    WHERE   E.manager_id = C.employee_id
),
CTE2 AS (
    SELECT  DISTINCT
            C.employee_id,
            C.employee_name,
            C.level,
            COUNT(E.employee_id) OVER (PARTITION BY C.employee_id) AS team_size,
            COALESCE(SUM(E.salary) OVER (PARTITION BY C.employee_id), 0) + C.salary AS budget
    FROM    CTE AS C
    LEFT JOIN LATERAL (
        WITH RECURSIVE CTE1 AS (
            SELECT  E.employee_id,
                    E.manager_id,
                    E.salary
            FROM    Employees AS E
            WHERE   E.manager_id = C.employee_id
            UNION ALL
            SELECT  EE.employee_id,
                    EE.manager_id,
                    EE.salary
            FROM    CTE1 AS CC, Employees AS EE
            WHERE   EE.manager_id = CC.employee_id
        )
        SELECT  employee_id,
                manager_id,
                salary
        FROM    CTE1
    ) AS E
    ON 1 = 1
)
SELECT  employee_id,
        employee_name,
        level,
        team_size,
        budget
FROM    CTE2
ORDER BY level, budget DESC, employee_name;