import pandas as pd


def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    df = orders.groupby("customer_number").size().reset_index(name="count")
    df = df[df["count"] == df["count"].max()]
    return df[["customer_number"]]
