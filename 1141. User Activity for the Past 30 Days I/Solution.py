import pandas as pd


def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    return (
        activity[activity["activity_date"].between("2019-06-28", "2019-07-27")]
        .rename(columns={"activity_date": "day"})
        .groupby("day")["user_id"]
        .nunique()
        .reset_index(name="active_users")
    )
