from typing import List


class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        if not roads:
            return 0

        degrees = [0] * n
        for a, b in roads:
            degrees[a] += 1
            degrees[b] += 1

        max1 = max2 = 0
        for degree in degrees:
            if degree > max1:
                max1, max2 = degree, max1
            elif degree > max2 and degree < max1:
                max2 = degree

        cnt1, cnt2 = degrees.count(max1), degrees.count(max2)
        if cnt1 == 1:
            edge_count = 0
            for a, b in roads:
                if (
                    degrees[a] == max1
                    and degrees[b] == max2
                    or degrees[a] == max2
                    and degrees[b] == max1
                ):
                    edge_count += 1
            return max1 + max2 - (1 if edge_count == cnt2 else 0)
        else:
            edge_count, limit = 0, cnt1 * (cnt1 - 1) // 2
            for a, b in roads:
                if degrees[a] == max1 and degrees[b] == max1:
                    edge_count += 1
            return 2 * max1 - (1 if edge_count == limit else 0)
