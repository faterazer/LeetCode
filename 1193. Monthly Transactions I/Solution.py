import pandas as pd


def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions["month"] = transactions["trans_date"].dt.strftime("%Y-%m")
    df = (
        transactions.groupby(["month", "country"], dropna=False)
        .agg(
            trans_count=pd.NamedAgg("id", aggfunc="count"),
            approved_count=pd.NamedAgg("state", aggfunc=lambda x: sum(x == "approved")),
            trans_total_amount=pd.NamedAgg("amount", aggfunc="sum"),
            approved_total_amount=pd.NamedAgg("amount", aggfunc=lambda x: sum(x[transactions["state"] == "approved"])),
        )
        .reset_index()
    )
    return df
