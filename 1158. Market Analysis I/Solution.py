import pandas as pd


def market_analysis(users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:
    cnt_df = orders[orders["order_date"].dt.year == 2019]
    cnt_df = cnt_df.groupby("buyer_id").size().reset_index(name="orders_in_2019")
    ans_df = pd.merge(users, cnt_df, how="left", left_on="user_id", right_on="buyer_id")
    ans_df = ans_df[["user_id", "join_date", "orders_in_2019"]]
    ans_df.rename(columns={"user_id": "buyer_id"}, inplace=True)
    ans_df.fillna(0, inplace=True)
    return ans_df
