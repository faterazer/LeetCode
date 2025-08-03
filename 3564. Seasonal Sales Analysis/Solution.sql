-- Write your PostgreSQL query statement below
WITH seasons AS (
    SELECT  month,
            season
    FROM    (VALUES (1, 'Winter'), (2, 'Winter'), (3, 'Spring'), 
                    (4, 'Spring'), (5, 'Spring'), (6, 'Summer'), 
                    (7, 'Summer'), (8, 'Summer'), (9, 'Fall'), 
                    (10, 'Fall'), (11, 'Fall'), (12, 'Winter')) AS tbl(month, season)
),
sales_with_product AS (
    SELECT  (SELECT season from seasons WHERE date_part('month', sale_date) = seasons.month) AS season,
            category,
            SUM(quantity) AS total_quantity,
            SUM(quantity * price) AS total_revenue
    FROM    sales
    JOIN    products
    ON  sales.product_id = products.product_id
    GROUP BY category, season
),
sales_ranking AS (
    SELECT  season,
            category,
            total_quantity,
            total_revenue,
            RANK() OVER (PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC) AS rank
    FROM    sales_with_product
)
SELECT  season,
        category,
        total_quantity,
        total_revenue
FROM    sales_ranking
WHERE   rank = 1
ORDER BY season;