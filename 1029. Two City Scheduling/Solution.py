from typing import List
import bisect


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda cost: cost[0] - cost[1])
        n = len(costs) >> 1
        return sum([cost[0] for cost in costs[:n]]) + sum([cost[1] for cost in costs[n:]])
