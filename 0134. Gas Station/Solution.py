from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        ans = min_s = s = 0
        for i, (g, c) in enumerate(zip(gas, cost)):
            s += g - c
            if s < min_s:
                min_s = s
                ans = i + 1
        return -1 if s < 0 else ans
