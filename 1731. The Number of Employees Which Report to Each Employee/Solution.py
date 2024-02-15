import pandas as pd


def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    df = (
        employees.groupby(by="reports_to")
        .agg({"employee_id": "count", "age": "mean"})
        .reset_index()
        .rename(columns={"employee_id": "reports_count", "age": "average_age"})
    )
    df = df.merge(employees[["employee_id", "name"]], left_on="reports_to", right_on="employee_id")
    df["average_age"] = df["average_age"].apply(lambda x: int(x + 0.5))
    return df[["employee_id", "name", "reports_count", "average_age"]]
