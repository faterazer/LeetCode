from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        res = mx = 0
        for i, e in enumerate(arr):
            mx = max(mx, e)
            if mx == i:
                res += 1
        return res
