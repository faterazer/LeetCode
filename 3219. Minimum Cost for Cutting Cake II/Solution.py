from typing import List


class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        ans = 0
        i = j = 0
        while i < m - 1 or j < n - 1:
            if i == m - 1:
                ans += verticalCut[j] * m
                j += 1
            elif j == n - 1:
                ans += horizontalCut[i] * n
                i += 1
            elif horizontalCut[i] > verticalCut[j]:
                ans += horizontalCut[i] * (j + 1)
                i += 1
            else:
                ans += verticalCut[j] * (i + 1)
                j += 1
        return ans
