import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    logs.sort_values(by="id", inplace=True)
    consecutive_nums = set()
    for (id1, num1), (id2, num2), (id3, num3) in zip(logs.values, logs.values[1:], logs.values[2:]):
        if id1 == id2 - 1 == id3 - 2 and num1 == num2 == num3:
            consecutive_nums.add(num1)
    return pd.DataFrame({"ConsecutiveNums": list(consecutive_nums)})
