-- Write your PostgreSQL query statement below
SELECT
    user_id AS buyer_id,
    join_date AS join_date,
    COALESCE(cnt, 0) AS orders_in_2019
FROM
    Users
LEFT JOIN (
    SELECT
        buyer_id,
        COUNT(order_id) AS cnt
    FROM
        Orders
    WHERE
        order_date BETWEEN '2019-01-01' AND '2019-12-31'
    GROUP BY
        buyer_id
) AS t
ON Users.user_id = t.buyer_id
