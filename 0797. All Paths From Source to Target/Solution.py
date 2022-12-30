from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res, cur = [], []

        def dfs(source: int, dest: int) -> None:
            cur.append(source)
            if source == dest:
                res.append(cur.copy())
            else:
                for neighbour in graph[source]:
                    dfs(neighbour, dest)
            cur.pop()

        dfs(0, len(graph) - 1)
        return res
