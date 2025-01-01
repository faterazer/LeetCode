from typing import List


class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort()
        verticalCut.sort()
        i = j = ans = 0
        while i < m - 1 or j < n - 1:
            if i == m - 1:
                ans += verticalCut[j]
                j += 1
            elif j == n - 1:
                ans += horizontalCut[i]
                i += 1
            elif horizontalCut[i] < verticalCut[j]:
                ans += horizontalCut[i] * (n - j)
                i += 1
            else:
                ans += verticalCut[j] * (m - i)
                j += 1
        return ans
