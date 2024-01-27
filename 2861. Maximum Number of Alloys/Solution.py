from typing import List


class Solution:
    def maxNumberOfAlloys(
        self, n: int, k: int, budget: int, composition: List[List[int]], stock: List[int], cost: List[int]
    ) -> int:
        def valid(m) -> bool:
            for c in composition:
                accum = 0
                for i in range(n):
                    accum += max(c[i] * m - stock[i], 0) * cost[i]
                if accum <= budget:
                    return True
            return False

        left, right = 1, min(stock) + budget
        while left <= right:
            mid = left + ((right - left) // 2)
            if valid(mid):
                left = mid + 1
            else:
                right = mid - 1
        return right
