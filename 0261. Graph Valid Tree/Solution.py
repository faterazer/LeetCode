from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        tree = [-1] * n

        def findRoot(tree: List[int], x: int) -> int:
            if tree[x] == -1:
                return x
            root = findRoot(tree, tree[x])
            tree[x] = root
            return root

        for a, b in edges:
            roota, rootb = findRoot(tree, a), findRoot(tree, b)
            if roota == rootb:
                return False
            tree[rootb] = roota

        return len(edges) == n - 1
