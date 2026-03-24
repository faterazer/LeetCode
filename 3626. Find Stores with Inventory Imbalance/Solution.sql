WITH StoreInventoryStats AS (
    SELECT  store_id,
            product_name,
            quantity,
            price,
            COUNT(*) OVER (PARTITION BY store_id) AS product_count,
            ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price DESC, quantity DESC) AS rank_desc,
            ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price ASC, quantity DESC) AS rank_asc
    FROM    inventory
)
SELECT  stores.store_id,
        stores.store_name,
        stores.location,
        exp.product_name AS most_exp_product,
        chp.product_name AS cheapest_product,
        ROUND(chp.quantity::NUMERIC / exp.quantity::NUMERIC, 2) AS imbalance_ratio
FROM    StoreInventoryStats AS exp
JOIN    StoreInventoryStats AS chp
ON  exp.store_id = chp.store_id
JOIN    stores
ON  exp.store_id = stores.store_id
WHERE   exp.rank_desc = 1
    AND chp.rank_asc = 1
    AND exp.product_count >= 3
    AND exp.quantity < chp.quantity
ORDER BY
    imbalance_ratio DESC,
    stores.store_name ASC
