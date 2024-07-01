from typing import List


class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        n = len(values)
        graph = [[] for _ in range(n)]
        for x, y, t in edges:
            graph[x].append((y, t))
            graph[y].append((x, t))

        res = 0
        visited = [0] * n

        def dfs(x: int, remainingTime: int, curValues: int) -> None:
            if visited[x] == 0:
                curValues += values[x]
            visited[x] += 1

            if x == 0:
                nonlocal res
                res = max(res, curValues)

            for y, t in graph[x]:
                if t <= remainingTime:
                    dfs(y, remainingTime - t, curValues)

            visited[x] -= 1
            if visited[x] == 0:
                curValues -= values[x]

        dfs(0, maxTime, 0)

        return res
