import pandas as pd


def queries_stats(queries: pd.DataFrame) -> pd.DataFrame:
    queries["quality"] = queries["rating"] / queries["position"]
    queries["poor_query_percentage"] = queries["rating"].apply(lambda x: int(x < 3) * 100)
    group_df = queries.groupby(by="query_name")[["quality", "poor_query_percentage"]].agg("mean").round(2).reset_index()
    return group_df
