import pandas as pd


def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    income = accounts["income"]
    return pd.DataFrame(
        {
            "category": ["Low Salary", "Average Salary", "High Salary"],
            "accounts_count": [
                (income < 20000).sum(),
                ((income >= 20000) & (income <= 50000)).sum(),
                (income > 50000).sum(),
            ],
        }
    )
