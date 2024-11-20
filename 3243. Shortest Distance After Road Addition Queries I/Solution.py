from typing import List


class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        roads = [[] for _ in range(n)]
        f = list(range(n))
        ans = []

        for u, v in queries:
            roads[u].append(v)
            if f[v] > f[u] + 1:
                f[v] = f[u] + 1
                for i in range(v, n):
                    f[i] = min(f[i], f[i - 1] + 1)
                    for j in roads[i]:
                        f[j] = min(f[j], f[i] + 1)
            ans.append(f[n - 1])
        return ans
