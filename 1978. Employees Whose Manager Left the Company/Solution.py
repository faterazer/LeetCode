import pandas as pd


def find_employees(employees: pd.DataFrame) -> pd.DataFrame:
    condition = (employees["salary"] < 30000) & ~employees["manager_id"].isna() & ~employees["manager_id"].isin(employees["employee_id"])
    return employees[condition][["employee_id"]].sort_values(by="employee_id")
