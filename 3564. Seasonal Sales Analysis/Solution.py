import pandas as pd


def seasonal_sales_analysis(products: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(sales, products, on="product_id")
    seasons = ["Winter", "Spring", "Summer", "Fall"]
    df["season"] = sales["sale_date"].apply(lambda x: seasons[x.month % 12 // 3])
    df["revenus"] = sales["quantity"] * sales["price"]
    df = (
        df.groupby(["season", "category"], as_index=False)
        .agg(total_quantity=("quantity", "sum"), total_revenue=("revenus", "sum"))
        .sort_values(by=["season", "total_quantity", "total_revenue"], ascending=[True, False, False])
        .drop_duplicates(subset="season", keep="first")
    )
    return df[["season", "category", "total_quantity", "total_revenue"]]
