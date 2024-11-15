from typing import List


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        tree = [[] for _ in range(n)]
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)

        ans = 0

        def dfs(node: int, parent: int) -> None:
            size, sz0, ok = 1, 0, True
            for x in tree[node]:
                if x == parent:
                    continue
                sz = dfs(x, node)
                if sz0 == 0:
                    sz0 = sz
                elif sz0 != sz:
                    ok = False
                size += sz
            nonlocal ans
            ans += ok
            return size

        dfs(0, -1)
        return ans
