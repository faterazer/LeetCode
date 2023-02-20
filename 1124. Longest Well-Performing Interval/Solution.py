from typing import List


class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        res = score = 0
        memo = {}
        for i, hour in enumerate(hours):
            score += 1 if hour > 8 else -1
            if score > 0:
                res = i + 1
            else:
                memo.setdefault(score, i)
                if score - 1 in memo:
                    res = max(res, i - memo[score - 1])
        return res
