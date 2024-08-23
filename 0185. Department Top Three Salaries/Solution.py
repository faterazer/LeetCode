import pandas as pd


def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    employee["rank"] = employee.groupby("departmentId")["salary"].rank(method="dense", ascending=False)
    employee.rename(columns={"name": "Employee", "salary": "Salary"}, inplace=True)
    department.rename(columns={"name": "Department"}, inplace=True)
    df = pd.merge(employee, department, left_on="departmentId", right_on="id")
    df = df[df["rank"] <= 3]
    return df[["Department", "Employee", "Salary"]]
