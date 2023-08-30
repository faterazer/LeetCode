import pandas as pd


def students_and_examinations(
    students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame
) -> pd.DataFrame:
    df = pd.merge(left=students, right=subjects, how="cross")
    grouped = examinations.groupby(["student_id", "subject_name"]).size().reset_index(name="attended_exams")
    df = df.merge(right=grouped, on=["student_id", "subject_name"], how="left")
    df["attended_exams"].fillna(0, inplace=True)
    df.sort_values(["student_id", "subject_name"], inplace=True)
    return df[["student_id", "student_name", "subject_name", "attended_exams"]]
