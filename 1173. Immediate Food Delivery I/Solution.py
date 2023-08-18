import pandas as pd


def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    is_valid = delivery["order_date"] == delivery["customer_pref_delivery_date"]
    immediate_percentage = round(is_valid.sum() / len(delivery) * 100, 2)
    return pd.DataFrame({"immediate_percentage": [immediate_percentage]})
