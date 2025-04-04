-- Write your PostgreSQL query statement below
SELECT
    Signups.user_id,
    ROUND(AVG(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END), 2) AS confirmation_rate
FROM
    Signups
LEFT JOIN
    Confirmations
ON
    Signups.user_id = Confirmations.user_id
GROUP BY
    Signups.user_id
