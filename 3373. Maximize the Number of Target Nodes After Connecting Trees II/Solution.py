class Solution:
    def maxTargetNodes(self, edges1: list[list[int]], edges2: list[list[int]]) -> list[int]:
        def buildTree(edges: list[list[int]]) -> list[list[int]]:
            n = len(edges) + 1
            tree = [[] for _ in range(n)]
            for u, v in edges:
                tree[u].append(v)
                tree[v].append(u)
            return tree

        tree1, tree2 = buildTree(edges1), buildTree(edges2)

        def count(tree: list[int], x: int, parent: int, d: int, cnt: list[int]) -> None:
            cnt[d] += 1
            for child in tree[x]:
                if child != parent:
                    count(tree, child, x, d ^ 1, cnt)

        cnt1, cnt2 = [0] * len(tree1), [0] * len(tree2)
        count(tree1, 0, -1, 0, cnt1)
        count(tree2, 0, -1, 0, cnt2)
        max2 = max(cnt2)

        ans = [max2] * len(tree1)

        def dfs(x: int, parent: int, d: int) -> None:
            ans[x] += cnt1[d]
            for child in tree1[x]:
                if child != parent:
                    dfs(child, x, d ^ 1)

        dfs(0, -1, 0)
        return ans
