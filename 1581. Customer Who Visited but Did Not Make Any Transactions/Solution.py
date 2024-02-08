import pandas as pd


def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    df = visits[~visits["visit_id"].isin(transactions["visit_id"])]
    return df.groupby(by="customer_id")["customer_id"].count().reset_index(name="count_no_trans")
