from typing import List


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        l, r = 0, len(arr)
        while l < r:
            m = l + ((r - l) >> 1)
            if arr[m] - m - 1 < k:
                l = m + 1
            else:
                r = m
        return l + k
