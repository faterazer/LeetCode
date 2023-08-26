import pandas as pd


def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    groups = daily_sales.groupby(["date_id", "make_name"])
    df = groups.agg(unique_leads=("lead_id", "nunique"), unique_partners=("partner_id", "nunique")).reset_index()
    return df
