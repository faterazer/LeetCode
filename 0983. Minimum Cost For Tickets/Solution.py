from typing import List


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        f = [0] * (n + 1)
        j, k = 0, 0
        for i, d in enumerate(days):
            while d - days[j] >= 7:
                j += 1
            while d - days[k] >= 30:
                k += 1
            f[i + 1] = min(f[i] + costs[0], f[j] + costs[1], f[k] + costs[2])
        return f[-1]
