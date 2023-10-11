from math import inf
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pre2_sell, pre1_buy, pre1_sell = 0, -inf, 0
        for price in prices:
            cur_buy = max(pre2_sell - price, pre1_buy)
            cur_sell = max(pre1_sell, cur_buy + price)
            pre2_sell, pre1_buy, pre1_sell = pre1_sell, cur_buy, cur_sell
        return pre1_sell
