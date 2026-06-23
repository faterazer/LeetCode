import pandas as pd


def find_zombie_sessions(app_events: pd.DataFrame) -> pd.DataFrame:
    processed_df = app_events.assign(
        ts=pd.to_datetime(app_events["event_timestamp"]),
        is_scroll=(app_events["event_type"] == "scroll"),
        is_click=(app_events["event_type"] == "click"),
        is_purchase=(app_events["event_type"] == "purchase"),
    )

    agg_df = processed_df.groupby("session_id", as_index=False).agg(
        user_id=("user_id", "max"),
        min_ts=("ts", "min"),
        max_ts=("ts", "max"),
        scroll_count=("is_scroll", "sum"),
        click_count=("is_click", "sum"),
        purchase_count=("is_purchase", "sum"),
    )
    agg_df["session_duration_minutes"] = (agg_df["max_ts"] - agg_df["min_ts"]).dt.total_seconds() / 60.0

    mask = (
        (agg_df["session_duration_minutes"] > 30)
        & (agg_df["purchase_count"] == 0)
        & (agg_df["scroll_count"] >= 5)
        & (agg_df["click_count"] < agg_df["scroll_count"] * 0.2)
    )

    result = agg_df.loc[mask, ["session_id", "user_id", "session_duration_minutes", "scroll_count"]]

    return result.sort_values(by=["scroll_count", "session_id"], ascending=[False, True]).reset_index(drop=True)
