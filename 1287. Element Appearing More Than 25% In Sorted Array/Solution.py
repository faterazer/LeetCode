import bisect
from typing import List


class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        for i in [n // 4, n * 2 // 4, n * 3 // 4]:
            if 4 * (bisect.bisect_right(arr, arr[i]) - bisect.bisect_left(arr, arr[i])) > n:
                return arr[i]
        return 0
