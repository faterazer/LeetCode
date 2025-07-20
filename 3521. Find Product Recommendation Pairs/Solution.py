import pandas as pd


def find_product_recommendation_pairs(product_purchases: pd.DataFrame, product_info: pd.DataFrame) -> pd.DataFrame:
    # 预过滤和去重：只保留需要的列并去除重复购买记录
    base = (
        product_purchases[["user_id", "product_id"]]
        .merge(product_info[["product_id", "category"]], on="product_id")
        .drop_duplicates(["user_id", "product_id"])
    )

    # 自连接生成产品对，使用query过滤有效组合
    pairs = base.merge(base, on="user_id", suffixes=("_1", "_2")).query("product_id_1 < product_id_2")

    # 聚合计算并一次性完成重命名
    result = (
        pairs.groupby(["product_id_1", "product_id_2"], as_index=False)
        .agg(product1_category=("category_1", "first"), product2_category=("category_2", "first"), customer_count=("user_id", "nunique"))
        .query("customer_count >= 3")
        .rename(columns={"product_id_1": "product1_id", "product_id_2": "product2_id"})
        .sort_values(by=["customer_count", "product1_id", "product2_id"], ascending=[False, True, True])
    )

    return result
