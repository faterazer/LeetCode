from typing import List


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        res, max_i = -1, values[0]
        for j in range(1, len(values)):
            res = max(res, max_i + values[j] - j)
            max_i = max(max_i, values[j] + j)
        return res
