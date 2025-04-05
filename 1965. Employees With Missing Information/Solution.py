import pandas as pd


def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:
    st1, st2 = set(employees["employee_id"].tolist()), set(salaries["employee_id"].tolist())
    ids = (st1 - st2) | (st2 - st1)
    return pd.DataFrame({"employee_id": list(ids)}).sort_values("employee_id")
