import pandas as pd


def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    groups = activities.groupby("sell_date")
    res = groups.agg(
        num_sold=("product", "nunique"),
        products=("product", lambda x: ",".join(sorted(set(x)))),
    ).reset_index()
    res.sort_values("sell_date", inplace=True)
    return res
