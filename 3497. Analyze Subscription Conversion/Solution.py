import pandas as pd


def analyze_subscription_conversion(user_activity: pd.DataFrame) -> pd.DataFrame:
    paid_users = set(user_activity[user_activity["activity_type"] == "paid"]["user_id"])
    user_activity = user_activity[user_activity["user_id"].isin(paid_users)]
    user_activity["activity_duration"] += 1e-8
    df1 = (
        user_activity[user_activity["activity_type"] == "free_trial"]
        .groupby("user_id")
        .agg(trial_avg_duration=("activity_duration", lambda x: x.mean().round(2)))
        .reset_index()
    )
    df2 = (
        user_activity[user_activity["activity_type"] == "paid"]
        .groupby("user_id")
        .agg(paid_avg_duration=("activity_duration", lambda x: x.mean().round(2)))
        .reset_index()
    )
    df = pd.merge(df1, df2, on="user_id").sort_values("user_id")
    return df
