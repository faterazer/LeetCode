from typing import List


class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = [0] * 60
        res = 0
        for t in time:
            res += cnt[(60 - t % 60) % 60]
            cnt[t % 60] += 1
        return res
