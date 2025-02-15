import pandas as pd


def last_passenger(queue: pd.DataFrame) -> pd.DataFrame:
    queue.sort_values(by="turn", inplace=True)
    cumulative_SUM, person_name = 0, None
    for line in queue.itertuples():
        cumulative_SUM += line.weight
        if cumulative_SUM > 1000:
            break
        person_name = line.person_name
    return pd.DataFrame({"person_name": [person_name]})
