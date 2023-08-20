import pandas as pd


def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees["total_time"] = employees["out_time"] - employees["in_time"]
    employees = employees.groupby(["emp_id", "event_day"])["total_time"].sum().reset_index()
    employees.rename(columns={"event_day": "day"}, inplace=True)
    return employees
