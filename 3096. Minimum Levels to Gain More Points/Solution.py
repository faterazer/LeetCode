from typing import List


class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        s = sum(possible) * 2 - len(possible)
        pre_sum = 0
        for i, x in enumerate(possible[:-1]):
            pre_sum += x * 2 - 1
            if pre_sum > s - pre_sum:
                return i + 1
        return -1
