import math
from typing import List


class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        res = -math.inf
        f0 = f1 = -1e4
        for x in arr:
            f1 = max(f0, f1 + x)
            f0 = max(f0, 0) + x
            res = max(res, f0, f1)
        return res
