from collections import defaultdict
from typing import List


class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [0] * n

        def dfs(x: int) -> int:
            if visited[x]:
                return 0
            visited[x] = 1
            return sum(dfs(neighbour) for neighbour in graph[x]) + 1

        res = counted = 0
        for i in range(n):
            cnt = dfs(i)
            res += cnt * counted
            counted += cnt
        return res
