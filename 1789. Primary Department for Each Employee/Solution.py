import pandas as pd


def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    condition = (employee["primary_flag"] == "Y") | (~employee["employee_id"].duplicated(keep=False))
    return employee[condition].drop("primary_flag", axis=1)
