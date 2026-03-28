import numpy as np
import pandas as pd


def find_polarized_books(books: pd.DataFrame, reading_sessions: pd.DataFrame) -> pd.DataFrame:
    book_stats = (
        reading_sessions.assign(is_extreme=lambda x: (x["session_rating"] >= 4) | (x["session_rating"] <= 2))
        .groupby("book_id", as_index=False)
        .agg(
            total_sessions=("session_id", "count"),
            max_rating=("session_rating", "max"),
            min_rating=("session_rating", "min"),
            polarization_score=("is_extreme", "mean"),
        )
        .query("total_sessions >= 5 and max_rating >= 4 and min_rating <= 2 and polarization_score >= 0.6")
        .assign(
            rating_spread=lambda x: x["max_rating"] - x["min_rating"],
            polarization_score=lambda x: np.floor(x["polarization_score"] * 100 + 0.5) / 100,
        )[["book_id", "rating_spread", "polarization_score"]]
    )
    return book_stats.merge(books, on="book_id", how="inner").sort_values(
        by=["polarization_score", "title"], ascending=[False, False]
    )[["book_id", "title", "author", "genre", "pages", "rating_spread", "polarization_score"]]
