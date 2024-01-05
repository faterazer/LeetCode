import pandas as pd


def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    df = my_numbers.drop_duplicates(subset=["num"], keep=False)
    return pd.DataFrame({"num": [df["num"].max()]})
