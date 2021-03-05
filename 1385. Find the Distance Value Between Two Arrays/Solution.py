import bisect
from typing import List


class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        res = 0
        for x in arr1:
            i = bisect.bisect_left(arr2, x)
            if i < len(arr2) and abs(x - arr2[i]) <= d or i > 0 and abs(x - arr2[i - 1]) <= d:
                continue
            res += 1
        return res
