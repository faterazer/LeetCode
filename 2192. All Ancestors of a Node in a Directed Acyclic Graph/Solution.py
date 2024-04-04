from typing import List


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)

        def dfs(node: int) -> None:
            visited[node] = beg
            for child in graph[node]:
                if visited[child] != beg:
                    res[child].append(beg)
                    dfs(child)

        res = [[] for _ in range(n)]
        visited = [-1] * n
        for beg in range(n):
            dfs(beg)
        return res
