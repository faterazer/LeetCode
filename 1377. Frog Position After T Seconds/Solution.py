from typing import List


class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        tree = [[] for _ in range(n + 1)]
        tree[1] = [0]
        for x, y in edges:
            tree[x].append(y)
            tree[y].append(x)

        def dfs(vertice: int, parent: int, left_t: int) -> int:
            if left_t == 0:
                return vertice == target
            if vertice == target:
                return len(tree[vertice]) == 1
            for neighbour in tree[vertice]:
                if neighbour == parent:
                    continue
                choices = dfs(neighbour, vertice, left_t - 1)
                if choices:
                    return choices * (len(tree[vertice]) - 1)
            return 0

        choices = dfs(1, 0, t)
        return 1 / choices if choices else 0
