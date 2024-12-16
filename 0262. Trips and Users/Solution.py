import pandas as pd


def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # 找出被禁用的用户 ID
    banned_users = set(users[users["banned"] == "Yes"]["users_id"])

    # 筛选出 client_id 和 driver_id 都不在 banned_users 中的 trips
    trips = trips[~trips["client_id"].isin(banned_users) & ~trips["driver_id"].isin(banned_users)]

    # 将 request_at 转换为日期类型并筛选日期范围
    trips["request_at"] = pd.to_datetime(trips["request_at"])
    start_date = pd.to_datetime("2013-10-01")
    end_date = pd.to_datetime("2013-10-03")
    trips = trips[(trips["request_at"] >= start_date) & (trips["request_at"] <= end_date)]

    # 计算取消率
    trips["is_cancelled"] = trips["status"] != "completed"
    res_df = trips.groupby("request_at")["is_cancelled"].mean().reset_index(name="Cancellation Rate")

    # 保留两位小数并重命名列
    res_df["Cancellation Rate"] = res_df["Cancellation Rate"].round(2)
    res_df.rename(columns={"request_at": "Day"}, inplace=True)

    return res_df[["Day", "Cancellation Rate"]]
