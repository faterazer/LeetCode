from typing import List


class UnionFind:
    def __init__(self, n: int) -> None:
        self.size = n
        self.tree = [-1] * n
        self.weight = [1.0] * n

    def findRoot(self, x: int) -> int:
        if self.tree[x] == -1:
            return x
        root = self.findRoot(self.tree[x])
        self.weight[x] *= self.weight[self.tree[x]]
        self.tree[x] = root
        return root

    def union(self, a: int, b: int, value: float) -> None:
        rootA, rootB = self.findRoot(a), self.findRoot(b)
        if rootA != rootB:
            self.tree[rootA] = rootB
            self.weight[rootA] = value / self.weight[a] * self.weight[b]

    def compute(self, a: int, b: int) -> float:
        rootA, rootB = self.findRoot(a), self.findRoot(b)
        if rootA != rootB:
            return -1.0
        else:
            return self.weight[a] / self.weight[b]


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        unionFind = UnionFind(2 * len(equations))
        idMap = {}
        idCode = 0
        for (a, b), value in zip(equations, values):
            if a not in idMap:
                idMap[a] = idCode
                idCode += 1
            if b not in idMap:
                idMap[b] = idCode
                idCode += 1
            unionFind.union(idMap[a], idMap[b], value)

        res = []
        for a, b in queries:
            if a not in idMap or b not in idMap:
                res.append(-1.0)
            else:
                res.append(unionFind.compute(idMap[a], idMap[b]))
        return res
