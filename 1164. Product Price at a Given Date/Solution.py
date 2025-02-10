import pandas as pd


def price_at_given_date(products: pd.DataFrame) -> pd.DataFrame:
    df1 = products[products["change_date"] <= pd.to_datetime("2019-08-16")]
    df1 = df1.sort_values(by="change_date", ascending=False).drop_duplicates(subset="product_id")
    df1["price"] = df1["new_price"]

    df2 = products[products["change_date"] > pd.to_datetime("2019-08-16")]
    df2 = df2[~df2["product_id"].isin(df1["product_id"])].drop_duplicates(subset="product_id")
    df2["price"] = 10

    return pd.concat([df1, df2], axis=0)[["product_id", "price"]]
