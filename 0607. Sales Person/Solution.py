import pandas as pd


def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=company, right=orders, on="com_id")
    red_df = df[df["name"] == "RED"]
    invalid_ids = red_df["sales_id"].unique()
    res_df = sales_person[~sales_person["sales_id"].isin(invalid_ids)]
    return res_df[["name"]]
