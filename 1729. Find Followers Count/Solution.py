import pandas as pd


def count_followers(followers: pd.DataFrame) -> pd.DataFrame:
    df = followers.groupby(by="user_id")["follower_id"].count().reset_index(name="followers_count")
    df.sort_values(by="user_id", inplace=True)
    return df
