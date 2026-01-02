class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        common_need = min(need1, need2)
        base = common_need * min(cost1 + cost2, costBoth)
        return base + (need1 - common_need) * min(cost1, costBoth) + (need2 - common_need) * (min(cost2, costBoth))
