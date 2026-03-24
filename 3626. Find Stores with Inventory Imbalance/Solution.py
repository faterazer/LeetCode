import pandas as pd


def find_inventory_imbalance(stores: pd.DataFrame, inventory: pd.DataFrame) -> pd.DataFrame:
    columns = ["store_id", "store_name", "location", "most_exp_product", "cheapest_product", "imbalance_ratio"]

    product_count = inventory.groupby("store_id").size()
    valid_store_ids = product_count[product_count >= 3].index
    inventory_filtered = inventory[inventory["store_id"].isin(valid_store_ids)]
    if inventory_filtered.empty:
        return pd.DataFrame(columns=columns)

    most_exp = inventory_filtered.sort_values(by=["price", "quantity"], ascending=[False, False]).drop_duplicates(
        subset="store_id", keep="first"
    )[["store_id", "product_name", "quantity"]]
    cheapest = inventory_filtered.sort_values(by=["price", "quantity"], ascending=[True, False]).drop_duplicates(
        subset="store_id", keep="first"
    )[["store_id", "product_name", "quantity"]]
    merged = pd.merge(most_exp, cheapest, on="store_id", suffixes=("_exp", "_chp"))
    imbalanced = merged[merged["quantity_exp"] < merged["quantity_chp"]].copy()
    if imbalanced.empty:
        return pd.DataFrame(columns=columns)

    imbalanced["imbalance_ratio"] = (imbalanced["quantity_chp"] / imbalanced["quantity_exp"]).round(2)
    final_df = pd.merge(imbalanced, stores, on="store_id")
    final_df = final_df.rename(columns={"product_name_exp": "most_exp_product", "product_name_chp": "cheapest_product"})
    result = (
        final_df[columns]
        .sort_values(by=["imbalance_ratio", "store_name"], ascending=[False, True])
        .reset_index(drop=True)
    )
    return result
