import re

import pandas as pd


def find_invalid_ips(logs: pd.DataFrame) -> pd.DataFrame:
    def validate_ipv4_addr(email: str) -> bool:
        pattern = r"^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])$"
        match = re.match(pattern, email)
        return bool(match)

    ans_df = logs[~logs["ip"].apply(validate_ipv4_addr)]
    ans_df = ans_df.groupby(by="ip")["ip"].agg(invalid_count="count").reset_index()
    ans_df = ans_df.sort_values(by=["invalid_count", "ip"], ascending=[False, False])
    return ans_df
