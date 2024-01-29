import pandas as pd


def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(prices, units_sold, on="product_id", how="left")
    df = df[df["units"].isna() | ((df["purchase_date"] >= df["start_date"]) & (df["purchase_date"] <= df["end_date"]))]
    return (
        df.groupby("product_id")
        .agg(average_price=("units", lambda x: ((x * df["price"]).sum() / x.sum()).round(2)))
        .reset_index()
        .fillna(0)
    )
