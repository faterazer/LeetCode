from collections import defaultdict
from typing import List


class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        res = -1
        memo = defaultdict(int)
        for x in nums:
            d = sum(map(int, str(x)))
            if d in memo:
                res = max(res, x + memo[d])
            memo[d] = max(memo[d], x)
        return res
