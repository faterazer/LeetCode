import pandas as pd


def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    def is_triangle(row: pd.Series) -> str:
        if row["x"] + row["y"] > row["z"] and row["x"] + row["z"] > row["y"] and row["y"] + row["z"] > row["x"]:
            return "Yes"
        else:
            return "No"

    triangle["triangle"] = triangle.apply(is_triangle, axis=1)
    return triangle
