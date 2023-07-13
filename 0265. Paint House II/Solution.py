from typing import List


class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        idx1 = idx2 = -1
        for i, colors in enumerate(costs):
            last1, last2 = idx1, idx2
            idx1 = idx2 = -1
            for j, _ in enumerate(colors):
                if j != last1:
                    costs[i][j] += costs[i - 1][last1] if last1 >= 0 else 0
                else:
                    costs[i][j] += costs[i - 1][last2] if last2 >= 0 else 0

                if idx1 < 0 or costs[i][j] < colors[idx1]:
                    idx2, idx1 = idx1, j
                elif idx2 < 0 or costs[i][j] < colors[idx2]:
                    idx2 = j
        return costs[-1][idx1]
