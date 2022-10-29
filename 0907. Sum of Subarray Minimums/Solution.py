from typing import List


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        stack, dp = [], []
        for i, e in enumerate(arr):
            while stack and arr[stack[-1]] > e:
                stack.pop()
            j = stack[-1] if stack else -1
            dp.append((i - j) * e)
            if j >= 0:
                dp[-1] += dp[j]
            stack.append(i)
        return sum(dp) % (10**9 + 7)
