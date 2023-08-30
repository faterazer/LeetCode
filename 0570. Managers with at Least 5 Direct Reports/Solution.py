import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    grouped = employee.groupby("managerId").size().reset_index(name="count")
    grouped = grouped[grouped["count"] >= 5]
    df = pd.merge(left=employee, right=grouped, left_on="id", right_on="managerId", how="inner")
    return df[["name"]]
