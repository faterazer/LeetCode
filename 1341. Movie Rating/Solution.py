import pandas as pd


def movie_rating(movies: pd.DataFrame, users: pd.DataFrame, movie_rating: pd.DataFrame) -> pd.DataFrame:
    df = movie_rating.merge(users, on="user_id").merge(movies, on="movie_id")
    ans_df1 = (
        df.groupby("name")
        .agg(count=pd.NamedAgg("movie_id", "count"))
        .reset_index(names="results")
        .sort_values(["count", "results"], ascending=[False, True])
        .head(1)[["results"]]
    )
    ans_df2 = (
        df[df["created_at"].dt.strftime("%Y-%m") == "2020-02"]
        .groupby("title")
        .agg(average=pd.NamedAgg("rating", "mean"))
        .reset_index(names="results")
        .sort_values(["average", "results"], ascending=[False, True])
        .head(1)[["results"]]
    )
    return pd.concat([ans_df1, ans_df2])
