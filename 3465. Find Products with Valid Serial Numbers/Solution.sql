-- Write your PostgreSQL query statement below
SELECT  product_id,
        product_name,
        description
FROM    products
WHERE   description ~ '(?<!\S)SN\d{4}-\d{4}(?!\d)'
ORDER BY    product_id
