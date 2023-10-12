from math import inf
from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        f0, f1 = -inf, 0
        for price in prices:
            f0 = max(f0, f1 - price)
            f1 = max(f1, f0 + price - fee)
        return f1
