-- Write your PostgreSQL query statement below
WITH P AS (
    SELECT  user_id,
            p1.product_id,
            category
    FROM    ProductPurchases AS p1
    JOIN    ProductInfo AS p2
    ON   p1.product_id = p2.product_id
)
SELECT  p1.category AS category1,
        p2.category AS category2,
        COUNT(DISTINCT p1.user_id) AS customer_count
FROM    P AS p1
JOIN    P AS p2 
ON  p1.user_id = p2.user_id
WHERE   p1.product_id != p2.product_id AND p1.category < p2.category
GROUP BY p1.category, p2.category
HAVING COUNT(DISTINCT p1.user_id) >= 3
ORDER BY customer_count DESC, category1, category2;
