import re

import pandas as pd


def find_valid_emails(users: pd.DataFrame) -> pd.DataFrame:

    def validate_email(email):
        pattern = r"^[a-zA-Z0-9_]+@[a-zA-Z]+\.com$"
        match = re.match(pattern, email)
        return bool(match)

    return users[users["email"].apply(validate_email)].sort_values("user_id")
