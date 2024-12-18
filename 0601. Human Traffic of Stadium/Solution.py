import pandas as pd


def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:
    stadium = stadium[stadium["people"] >= 100].reset_index(drop=True)
    stadium["offset"] = stadium["id"] - stadium.index
    stadium["cnt"] = stadium.groupby("offset")["id"].transform("count")
    stadium = stadium[stadium["cnt"] >= 3]
    stadium.sort_values(by="visit_date", ascending=True, inplace=True)
    return stadium[["id", "visit_date", "people"]]
