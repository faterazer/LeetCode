from typing import List


class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        tree = list(range(n))

        def findRoot(x: int) -> int:
            if tree[x] == x:
                return x
            tree[x] = findRoot(tree[x])
            return tree[x]

        for a, b in edges:
            root_a, root_b = findRoot(a), findRoot(b)
            if root_a != root_b:
                tree[root_b] = root_a
        return findRoot(source) == findRoot(destination)
