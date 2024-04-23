from typing import List


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        base = sum(c * (1 - g) for c, g in zip(customers, grumpy))
        window_sum, res = sum(c * g for c, g in zip(customers[: minutes - 1], grumpy[: minutes - 1])), 0
        for i in range(minutes - 1, len(customers)):
            window_sum += customers[i] * grumpy[i]
            res = max(res, base + window_sum)
            window_sum -= customers[i - minutes + 1] * grumpy[i - minutes + 1]
        return res
