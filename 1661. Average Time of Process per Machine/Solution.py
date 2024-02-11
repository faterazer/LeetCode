import pandas as pd


def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    start_df = activity[activity["activity_type"] == "start"]
    end_df = activity[activity["activity_type"] == "end"]
    df = pd.merge(left=start_df, right=end_df, on=["machine_id", "process_id"], suffixes=("_start", "_end"))
    df["processing_time"] = df["timestamp_end"] - df["timestamp_start"]
    return df.groupby(by="machine_id")["processing_time"].mean().reset_index().round(3)
