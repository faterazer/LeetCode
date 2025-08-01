import pandas as pd


def find_category_recommendation_pairs(product_purchases: pd.DataFrame, product_info: pd.DataFrame, min_customers: int = 3) -> pd.DataFrame:
    # 1. 只保留需要的列
    user_cat = product_purchases[["user_id", "product_id"]].merge(product_info[["product_id", "category"]], on="product_id", how="inner")

    # 2. 自连接：同一用户购买的不同商品且类别不同
    pair = user_cat.merge(user_cat, on="user_id", suffixes=("_1", "_2"))
    pair = pair[pair["category_1"] < pair["category_2"]]

    # 3. 聚合：每个类别对的独立用户数
    counts = pair.groupby(["category_1", "category_2"], as_index=False).agg(customer_count=("user_id", "nunique"))

    # 4. 使用 min_customers 过滤
    qualified = counts[counts["customer_count"] >= min_customers]

    # 5. 排序并重命名列
    result = qualified.sort_values(by=["customer_count", "category_1", "category_2"], ascending=[False, True, True]).rename(
        columns={"category_1": "category1", "category_2": "category2"}
    )

    return result[["category1", "category2", "customer_count"]]
