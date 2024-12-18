-- Write your PostgreSQL query statement below
WITH filtered AS (
    SELECT
        id,
        visit_date,
        people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS rn
    FROM
        Stadium
    WHERE
        people >= 100
)
SELECT
    id,
    visit_date,
    people
FROM
    filtered
WHERE
    rn IN (
        SELECT
            rn
        FROM
            filtered
        GROUP BY
            rn
        HAVING
            COUNT(*) >= 3
    )
ORDER BY
    visit_date;
