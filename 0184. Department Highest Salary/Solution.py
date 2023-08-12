import pandas as pd


def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(left=employee, right=department, left_on="departmentId", right_on="id", how="left")
    df.rename(columns={"name_x": "Employee", "name_y": "Department", "salary": "Salary"}, inplace=True)
    max_salary = df.groupby(by="Department")["Salary"].transform("max")
    df = df[df["Salary"] == max_salary]
    return df[["Department", "Employee", "Salary"]]
