import pandas as pd


def find_students_who_improved(scores: pd.DataFrame) -> pd.DataFrame:
    return (
        scores.groupby(["student_id", "subject"], as_index=False)
        .agg(first_score=("score", "first"), latest_score=("score", "last"))
        .query("first_score < latest_score")
    )
