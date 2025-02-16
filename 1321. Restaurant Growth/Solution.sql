-- Write your PostgreSQL query statement below
WITH daily_sum AS (
    SELECT
        visited_on,
        SUM(amount) AS amount
    FROM
        Customer
    GROUP BY
        visited_on
),
windowed_sum AS (
    SELECT
        visited_on,
        SUM(amount) OVER (ORDER BY visited_on RANGE BETWEEN '6 days' PRECEDING AND CURRENT ROW) AS amount,
        (visited_on - '6 days'::interval) AS start_date
    FROM
        daily_sum
)
SELECT
    visited_on,
    amount,
    ROUND(amount::numeric / 7, 2) AS average_amount
FROM
    windowed_sum
WHERE EXISTS (
    SELECT 1
    FROM daily_sum
    WHERE visited_on = windowed_sum.start_date
);
