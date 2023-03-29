from typing import List


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        total = res = 0
        for x in sorted(satisfaction, reverse=True):
            if x <= -total:
                break
            total += x
            res += total
        return res
