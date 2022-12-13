from typing import List


class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        min_base_cost = min(baseCosts)
        if min_base_cost >= target:
            return min_base_cost

        margin = target - min_base_cost
        dp = [False] * (target + 1)
        for cost in baseCosts:
            if cost <= target:
                dp[cost] = True
            else:
                margin = min(margin, cost - target)

        for cost in toppingCosts:
            for _ in range(2):
                for i in range(target, -1, -1):
                    if dp[i]:
                        if i + cost <= target:
                            dp[i + cost] = True
                        else:
                            margin = min(margin, i + cost - target)
        for i in range(target, target - margin - 1, -1):
            if dp[i]:
                return i
        return target + margin
