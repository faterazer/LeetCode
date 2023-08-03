import pandas as pd


def find_customers_mk1(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=customers, right=orders, left_on="id", right_on="customerId", how="left")
    df = df[df["customerId"].isna()].rename(columns={"name": "Customers"})
    return df[["Customers"]]


def find_customers_mk2(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers[~customers["id"].isin(orders["customerId"])]
    df = df[["name"]].rename(columns={"name": "Customers"})
    return df
