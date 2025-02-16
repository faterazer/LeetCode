import pandas as pd


def restaurant_growth(customer: pd.DataFrame) -> pd.DataFrame:
    df = customer.sort_values("visited_on").groupby("visited_on")[["amount"]].sum()
    df = df.assign(
        amount=df["amount"].rolling("7D").sum(),
        average_amount=round(df["amount"].rolling("7D").mean(), 2),
    )
    return df[df.index >= df.index.min() + pd.DateOffset(6)].reset_index()
