import pandas as pd


def exchange_seats(seat: pd.DataFrame) -> pd.DataFrame:
    seat["group_id"] = (seat["id"] - 1) // 2
    seat.sort_values(by=["group_id", "id"], ascending=[True, False], inplace=True)
    seat["id"] = pd.RangeIndex(start=1, stop=seat.shape[0] + 1)
    return seat[["id", "student"]].reset_index(drop=True)
