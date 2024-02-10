import pandas as pd


def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    users_count = users.shape[0]
    df = register.groupby(by="contest_id")["user_id"].count().reset_index(name="percentage")
    df["percentage"] = (df["percentage"] / users_count * 100).round(2)
    df.sort_values(by=["percentage", "contest_id"], ascending=[False, True], inplace=True)
    return df
