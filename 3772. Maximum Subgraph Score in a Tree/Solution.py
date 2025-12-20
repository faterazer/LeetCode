class Solution:
    def maxSubgraphScore(self, n: int, edges: list[list[int]], good: list[int]) -> list[int]:
        graph = [[] for _ in range(n)]
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
        result = [0] * n

        def dfs(node: int, parent: int) -> None:
            result[node] = 1 if good[node] else -1
            for neighbour in graph[node]:
                if neighbour != parent:
                    dfs(neighbour, node)
                    result[node] += max(result[neighbour], 0)

        dfs(0, -1)

        def reroot(node: int, parent: int) -> None:
            for neighbour in graph[node]:
                if neighbour != parent:
                    result[neighbour] += max(result[node] - max(result[neighbour], 0), 0)
                    reroot(neighbour, node)

        reroot(0, -1)
        return result
