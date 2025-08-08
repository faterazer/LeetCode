from collections import defaultdict

import pandas as pd


def find_consistently_improving_employees(employees: pd.DataFrame, performance_reviews: pd.DataFrame) -> pd.DataFrame:
    employee2ratings = defaultdict(list)
    for line in performance_reviews.sort_values(by="review_date", ascending=False).itertuples():
        employee2ratings[line.employee_id].append(line.rating)

    df = []
    for employee_id, ratings in employee2ratings.items():
        if len(ratings) < 3:
            continue
        ratings = ratings[:3]
        if ratings[0] > ratings[1] > ratings[2]:
            df.append({"employee_id": employee_id, "improvement_score": ratings[0] - ratings[2]})
    df = pd.DataFrame(df)

    return df.merge(employees, on="employee_id").sort_values(by=["improvement_score", "name"], ascending=[False, True])[
        ["employee_id", "name", "improvement_score"]
    ]
