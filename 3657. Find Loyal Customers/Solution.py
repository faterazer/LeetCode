import pandas as pd


def find_loyal_customers(customer_transactions: pd.DataFrame) -> pd.DataFrame:
    processed_df = customer_transactions.assign(
        parsed_date=pd.to_datetime(customer_transactions["transaction_date"]),
        is_refund=(customer_transactions["transaction_type"] == "refund"),
    )

    agg_df = processed_df.groupby("customer_id", as_index=False).agg(
        transaction_cnt=("transaction_id", "count"),
        first_date=("parsed_date", "min"),
        last_date=("parsed_date", "max"),
        refund_rate=("is_refund", "mean"),
    )
    agg_df["date_span"] = (agg_df["last_date"] - agg_df["first_date"]).dt.days

    mask = (agg_df["transaction_cnt"] >= 3) & (agg_df["date_span"] >= 30) & (agg_df["refund_rate"] < 0.2)
    return agg_df[mask][["customer_id"]].sort_values("customer_id").reset_index(drop=True)
