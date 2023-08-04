import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views[views["author_id"] == views["viewer_id"]]
    df = df[["author_id"]].drop_duplicates()
    df.rename(columns={"author_id": "id"}, inplace=True)
    df.sort_values(by="id", inplace=True)
    return df
