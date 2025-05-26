import re

import pandas as pd


def find_valid_serial_products(products: pd.DataFrame) -> pd.DataFrame:

    def check(serial: str) -> bool:
        pattern = r"(?<!\S)SN\d{4}-\d{4}(?!\d)"
        return bool(re.search(pattern, serial))

    return products[products["description"].apply(check)].sort_values(by="product_id", ascending=True)
