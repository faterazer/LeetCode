import collections
from typing import List


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        c = collections.Counter(arr)
        res = -1
        for k, v in c.items():
            if k == v:
                res = max(res, k)
        return res
