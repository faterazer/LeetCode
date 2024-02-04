import pandas as pd


def top_travellers(users: pd.DataFrame, rides: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=users, right=rides, left_on="id", right_on="user_id", how="left")
    df.fillna(0, inplace=True)
    df = df.groupby(by=["name", "user_id"])["distance"].sum().reset_index(name="travelled_distance")
    df.sort_values(by=["travelled_distance", "name"], ascending=[False, True], inplace=True)
    return df[["name", "travelled_distance"]]
