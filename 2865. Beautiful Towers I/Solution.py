from typing import List


class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        stack = [n]
        suf = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1]
            while len(stack) > 1 and maxHeights[i] <= maxHeights[stack[-1]]:
                j = stack.pop()
                suf[i] -= maxHeights[j] * (stack[-1] - j)
            suf[i] += maxHeights[i] * (stack[-1] - i)
            stack.append(i)

        res, pre = 0, 0
        stack = [-1]
        for i in range(n):
            while len(stack) > 1 and maxHeights[i] <= maxHeights[stack[-1]]:
                j = stack.pop()
                pre -= maxHeights[j] * (j - stack[-1])
            pre += maxHeights[i] * (i - stack[-1])
            stack.append(i)
            res = max(res, pre + suf[i + 1])
        return res
