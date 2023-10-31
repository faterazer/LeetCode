from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left, right = 0, n - 1
        while left <= right:
            m = left + (right - left) // 2
            if citations[m] < n - m:
                left = m + 1
            else:
                right = m - 1
        return n - left
