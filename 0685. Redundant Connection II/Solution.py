from typing import List


class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parents = [-1] * (n + 1)
        dsu = [-1] * (n + 1)
        conflict = cycle = -1

        def findRoot(x: int) -> int:
            if dsu[x] == -1:
                return x
            dsu[x] = findRoot(dsu[x])
            return dsu[x]

        for i, (u, v) in enumerate(edges):
            if parents[v] != -1:
                conflict = i
            else:
                parents[v] = u
                root_u, root_v = findRoot(u), findRoot(v)
                if root_u == root_v:
                    cycle = i
                else:
                    dsu[v] = u

        if cycle == -1:
            return edges[conflict]
        if conflict == -1:
            return edges[cycle]
        return [parents[edges[conflict][1]], edges[conflict][1]]
