import bisect
from typing import List


class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        gap = len(arr) // 4
        for i in [gap, gap * 2, gap * 3]:
            if bisect.bisect_right(arr, arr[i]) - bisect.bisect_left(arr, arr[i]) > gap:
                return arr[i]
        return 0
