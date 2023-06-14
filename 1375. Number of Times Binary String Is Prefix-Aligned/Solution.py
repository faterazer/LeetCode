from typing import List


class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        res = total = last_idx = 0
        for idx in flips:
            last_idx = max(idx, last_idx)
            total += 1
            if total == last_idx:
                res += 1
        return res
