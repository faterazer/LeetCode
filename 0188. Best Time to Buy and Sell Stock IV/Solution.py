from math import inf
from typing import List


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        f = [[-inf, 0] for _ in range(k + 1)]
        f[0][0] = 0
        for price in prices:
            for i in range(1, k + 1):
                f[i][0] = max(f[i][0], f[i - 1][1] - price)
                f[i][1] = max(f[i][1], f[i][0] + price)
        return f[k][1]
