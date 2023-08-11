import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee[["salary"]].drop_duplicates()
    if len(df) < 2:
        return pd.DataFrame({"SecondHighestSalary": [None]})
    df = df.sort_values(by="salary", ascending=False)
    df.rename(columns={"salary": "SecondHighestSalary"}, inplace=True)
    return df.iloc[[1]]
