import pandas as pd


def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    cnt = product["product_key"].unique().size
    return customer.groupby("customer_id").filter(lambda x: x["product_key"].unique().size == cnt)[["customer_id"]].drop_duplicates()
