import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    df = employee[["salary"]].drop_duplicates()
    if len(df) < N:
        return pd.DataFrame({"getNthHighestSalary(2)": [None]})
    df.sort_values("salary", ascending=False, inplace=True)
    return df.iloc[[N - 1]]
