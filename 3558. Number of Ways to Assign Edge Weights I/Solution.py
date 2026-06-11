class Solution:
    def assignEdgeWeights(self, edges: list[list[int]]) -> int:
        n = len(edges) + 1
        tree = [[] for _ in range(n + 1)]
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        def dfs(x: int, parent: int) -> int:
            d = 0
            for y in tree[x]:
                if y != parent:
                    d = max(d, dfs(y, x) + 1)
            return d

        d = dfs(1, 0)
        return pow(2, d - 1, 10**9 + 7)
