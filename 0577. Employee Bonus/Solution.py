import pandas as pd


def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=employee, right=bonus, how="left", on="empId")
    df = df[df["bonus"].isna() | (df["bonus"] < 1000)]
    return df[["name", "bonus"]]
