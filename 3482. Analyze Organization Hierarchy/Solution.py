from collections import defaultdict

import pandas as pd


def analyze_organization_hierarchy(employees: pd.DataFrame) -> pd.DataFrame:
    tree = defaultdict(list)
    root = None
    for line in employees.itertuples():
        if not pd.isna(line.manager_id):
            tree[line.manager_id].append(line.employee_id)
        else:
            root = line.employee_id

    buff = {}

    def dfs(employee_id: int, level: int) -> tuple[int, int]:
        team_size = 0
        budget = employees.loc[employees["employee_id"] == employee_id, "salary"].values[0]
        for x in tree[employee_id]:
            sub_team_size, sub_budget = dfs(x, level + 1)
            team_size += sub_team_size
            budget += sub_budget
        buff[employee_id] = (level, team_size, budget)
        return team_size + 1, budget

    dfs(root, 1)

    employees["level"] = employees["employee_id"].apply(lambda x: buff[x][0])
    employees["team_size"] = employees["employee_id"].apply(lambda x: buff[x][1])
    employees["budget"] = employees["employee_id"].apply(lambda x: buff[x][2])
    employees.sort_values(by=["level", "budget", "employee_name"], ascending=[True, False, True], inplace=True)
    return employees[["employee_id", "employee_name", "level", "team_size", "budget"]]
