-- Write your PostgreSQL query statement below
WITH CTE AS (
    SELECT  employee_id,
            SUM(duration_hours) AS total_duration
    FROM    meetings
    GROUP BY employee_id, EXTRACT(WEEK FROM meeting_date), EXTRACT(YEAR FROM meeting_date)
    HAVING  SUM(duration_hours) > 20
)
SELECT  CTE.employee_id,
        employees.employee_name,
        employees.department,
        COUNT(CTE.employee_id) AS meeting_heavy_weeks
FROM    CTE
JOIN    employees
ON  CTE.employee_id = employees.employee_id
GROUP BY CTE.employee_id, employees.employee_name, employees.department
HAVING  COUNT(CTE.employee_id) > 1
ORDER BY    meeting_heavy_weeks DESC, employees.employee_name;
