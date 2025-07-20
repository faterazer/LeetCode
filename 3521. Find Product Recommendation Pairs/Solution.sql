-- Write your PostgreSQL query statement below
WITH Product AS (
    SELECT  user_id,
            ProductInfo.product_id,
            category
    FROM    ProductPurchases
    JOIN    ProductInfo
    ON  ProductPurchases.product_id = ProductInfo.product_id
)
SELECT  P1.product_id AS product1_id,
        P2.product_id AS product2_id,
        MAX(P1.category) AS product1_category,
        MAX(P2.category) AS product2_category,
        COUNT(P1.user_id) AS customer_count
FROM    Product AS P1
JOIN    Product AS P2
ON  P1.user_id = P2.user_id
WHERE P1.product_id < P2.product_id
GROUP BY P1.product_id, P2.product_id
HAVING COUNT(P1.user_id) >= 3
ORDER BY customer_count DESC, product1_id, product2_id;