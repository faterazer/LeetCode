-- Write your PostgreSQL query statement below
WITH Products_0816 AS (
    SELECT
        product_id,
        new_price AS price,
        change_date
    FROM
        Products
    WHERE
        change_date <= '2019-08-16'::date
)
(SELECT DISTINCT ON (product_id)
    product_id,
    price
FROM
    Products_0816
ORDER BY
    product_id, change_date DESC)
UNION ALL
(SELECT
    product_id,
    10 AS price
FROM
    Products
WHERE
    product_id NOT IN (
        SELECT
            product_id
        FROM
            Products_0816
    ))
