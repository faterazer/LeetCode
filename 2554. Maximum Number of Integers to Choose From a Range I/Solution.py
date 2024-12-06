from typing import List


class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned_st, ans = set(banned), 0
        for i in range(1, n + 1):
            if i > maxSum:
                break
            if i not in banned_st:
                maxSum -= i
                ans += 1
        return ans
