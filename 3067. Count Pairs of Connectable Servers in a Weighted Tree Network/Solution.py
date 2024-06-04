from typing import List


class Solution:
    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        n = len(edges) + 1
        graph = [[] for _ in range(n)]
        for a, b, w in edges:
            graph[a].append((b, w))
            graph[b].append((a, w))

        def dfs(x: int, parent: int, dist: int) -> int:
            r = dist % signalSpeed == 0
            for y, w in graph[x]:
                if y != parent:
                    r += dfs(y, x, dist + w)
            return r

        res = [0] * n
        for i, neighbours in enumerate(graph):
            if len(neighbours) < 2:
                continue

            accum = 0
            for x, w in neighbours:
                cnt = dfs(x, i, w)
                res[i] += accum * cnt
                accum += cnt
        return res
