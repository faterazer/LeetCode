import collections
from typing import Counter, List


class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        beg, end = float('inf'), float('-inf')
        growth_rate = {}
        for birth, death in logs:
            growth_rate[birth] = growth_rate.get(birth, 0) + 1 
            growth_rate[death] = growth_rate.get(death, 0) - 1
            beg = min(beg, birth)
            end = max(end, death)

        mx = tmp = res = 0
        for i in range(beg, end):
            if i in growth_rate:
                tmp += growth_rate[i]
                if tmp > mx:
                    mx = tmp
                    res = i
        return res
