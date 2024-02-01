import pandas as pd


def list_products(products: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=products, right=orders, on="product_id")
    df = df[df["order_date"].dt.strftime("%Y-%m") == "2020-02"]
    df = df.groupby(by="product_name")["unit"].sum().reset_index()
    return df[df["unit"] >= 100]
