from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = [-1] * (n + 1)

        def findRoot(x: int) -> int:
            if parent[x] == -1:
                return x
            parent[x] = findRoot(parent[x])
            return parent[x]

        for a, b in edges:
            root_a, root_b = findRoot(a), findRoot(b)
            if root_a == root_b:
                ans = [a, b]
            else:
                parent[root_b] = root_a
        return ans
