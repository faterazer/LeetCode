-- Write your PostgreSQL query statement below
SELECT  product_name,
        SUM(unit) AS unit
FROM    Products
JOIN    Orders
ON  Products.product_id = Orders.product_id
WHERE   to_char(order_date, 'yyyy-mm') LIKE '2020-02%'
GROUP BY    product_name
HAVING   SUM(unit) >= 100
