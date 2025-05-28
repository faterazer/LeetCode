class Solution:
    def maxTargetNodes(self, edges1: list[list[int]], edges2: list[list[int]], k: int) -> list[int]:

        def buildTree(edges: list[list[int]]) -> list[list[int]]:
            tree = [[] for _ in range(len(edges) + 1)]
            for u, v in edges:
                tree[u].append(v)
                tree[v].append(u)
            return tree

        def dfs(tree: list[list[int]], node: int, parent: int, depth: int) -> int:
            if depth < 0:
                return 0
            cnt = 1
            for child in tree[node]:
                if child != parent:
                    cnt += dfs(tree, child, node, depth - 1)
            return cnt

        tree1, tree2 = buildTree(edges1), buildTree(edges2)
        max2 = max(dfs(tree2, i, -1, k - 1) for i in range(len(tree2)))
        return [dfs(tree1, i, -1, k) + max2 for i in range(len(tree1))]
