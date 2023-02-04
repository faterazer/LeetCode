from typing import List


class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        max_val = 0
        for coin in sorted(coins):
            if coin > max_val + 1:
                break
            max_val += coin
        return max_val + 1
