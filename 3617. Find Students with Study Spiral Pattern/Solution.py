import pandas as pd


def find_study_spiral_pattern(students: pd.DataFrame, study_sessions: pd.DataFrame) -> pd.DataFrame:
    study_sessions["session_date"] = pd.to_datetime(study_sessions["session_date"])

    # 排序：确保 diff 是基于时间顺序计算的
    df = study_sessions.sort_values(by=["student_id", "session_date"])

    stats = (
        df.groupby("student_id")
        .agg(
            cycle_length=("subject", "nunique"),
            total_sessions=("session_id", "count"),
            total_study_hours=("hours_studied", "sum"),
            max_gap=("session_date", lambda x: x.diff().dt.days.max()),
        )
        .fillna(0)
    )  # 这里的 fillna 是处理 max_gap 第一行的 NaN

    # 筛选条件
    candidates = stats[
        (stats["cycle_length"] >= 3) & (stats["total_sessions"] >= 2 * stats["cycle_length"]) & (stats["max_gap"] <= 2)
    ]

    if candidates.empty:
        return pd.DataFrame(columns=["student_id", "student_name", "major", "cycle_length", "total_study_hours"])

    valid_student_ids = []
    candidate_sessions = df[df["student_id"].isin(candidates.index)]
    for student_id, group in candidate_sessions.groupby("student_id"):
        k = int(candidates.at[student_id, "cycle_length"])
        subjects = group["subject"]

        # 向量化比较：当前科目 vs K个周期后的科目
        matches = subjects == subjects.shift(-k)

        # 只要前 N-K 个都匹配，就是完美螺旋
        # group.shape[0] 是总行数
        if matches.iloc[: (group.shape[0] - k)].all():
            valid_student_ids.append(student_id)

    final_stats = candidates.loc[valid_student_ids].reset_index()
    result = final_stats.merge(students, on="student_id")
    result = result[["student_id", "student_name", "major", "cycle_length", "total_study_hours"]]
    return result.sort_values(by=["cycle_length", "total_study_hours"], ascending=[False, False])
