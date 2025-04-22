import pandas as pd


def sum_daily_odd_even(transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        transactions.groupby("transaction_date")["amount"]
        .agg(odd_sum=lambda x: sum(amount for amount in x if amount % 2 == 1), even_sum=lambda x: sum(amount for amount in x if amount % 2 == 0))
        .reset_index(names="transaction_date")
        .sort_values("transaction_date")
    )
