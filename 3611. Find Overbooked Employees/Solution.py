import pandas as pd


def find_overbooked_employees(employees: pd.DataFrame, meetings: pd.DataFrame) -> pd.DataFrame:
    result = (
        meetings
        # 步骤 1: 创建年和周的列，以进行分组
        .assign(year=lambda df: df["meeting_date"].dt.isocalendar().year, week=lambda df: df["meeting_date"].dt.isocalendar().week)
        # 步骤 2: 分组计算每周总时长 (对应 SQL CTE)
        .groupby(["employee_id", "year", "week"])["duration_hours"]
        .sum()
        .reset_index(name="total_duration")
        # 步骤 3: 筛选出“会议繁忙周” (对应 CTE 的 HAVING)
        .query("total_duration > 20")
        # 步骤 4: 按员工分组，计算繁忙周的次数
        .groupby("employee_id")
        .size()  # .size() 是高效且推荐的计数方法
        .reset_index(name="meeting_heavy_weeks")
        # 步骤 5: 筛选出繁忙周超过1次的员工 (对应主查询的 HAVING)
        .query("meeting_heavy_weeks > 1")
        # 步骤 6: 连接员工信息表 (对应 JOIN)
        .merge(employees, on="employee_id")
        # 步骤 7: 排序 (对应 ORDER BY)
        .sort_values(["meeting_heavy_weeks", "employee_name"], ascending=[False, True])
        # 步骤 8: 选择并重排最终的列 (对应 SELECT)
        [["employee_id", "employee_name", "department", "meeting_heavy_weeks"]]
    )

    return result
