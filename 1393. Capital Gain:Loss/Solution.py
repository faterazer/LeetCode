import pandas as pd


def capital_gainloss(stocks: pd.DataFrame) -> pd.DataFrame:
    buy_df = stocks[stocks["operation"] == "Buy"].groupby(by=["stock_name"])["price"].sum().reset_index(name="buy_price")
    sell_df = stocks[stocks["operation"] == "Sell"].groupby(by=["stock_name"])["price"].sum().reset_index(name="sell_price")
    df = pd.merge(buy_df, sell_df, on="stock_name")
    df["capital_gain_loss"] = df["sell_price"] - df["buy_price"]
    return df[["stock_name", "capital_gain_loss"]]
