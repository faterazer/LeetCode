import pandas as pd


def latest_login(logins: pd.DataFrame) -> pd.DataFrame:
    df = logins[logins["time_stamp"].dt.year == 2020]
    return df.groupby(by="user_id")["time_stamp"].max().reset_index(name="last_stamp")
