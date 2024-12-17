import pandas as pd


def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    dup = insurance[insurance.duplicated(subset="tiv_2015", keep=False)]["pid"]
    pos = insurance.drop_duplicates(subset=["lat", "lon"], keep=False)["pid"]

    tiv_2016_sum = insurance[insurance["pid"].isin(dup) & insurance["pid"].isin(pos)]["tiv_2016"].sum()
    return pd.DataFrame({"tiv_2016": [tiv_2016_sum]})
