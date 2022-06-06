import bisect
from typing import List, Tuple


class DisjointSetUnion:
    def __init__(self, n: int) -> None:
        self.tree = [-1] * n

    def findRoot(self, e: int) -> int:
        if self.tree[e] == -1:
            return e
        root = self.findRoot(self.tree[e])
        self.tree[e] = root
        return root

    def unionSet(self, a: int, b: int) -> bool:
        root_a, root_b = self.findRoot(a), self.findRoot(b)
        if root_a == root_b:
            return False
        self.tree[root_b] = root_a
        return True


class BIT:
    def __init__(self, n: int) -> None:
        self.tree = [float('inf')] * n
        self.id_rec = [-1] * n

    @staticmethod
    def lowbit(x: int) -> int:
        return x & -x

    def query(self, idx: int) -> int:
        minval, id_code = float('inf'), -1
        while idx < len(self.tree):
            if self.tree[idx] < minval:
                minval = self.tree[idx]
                id_code = self.id_rec[idx]
            idx += BIT.lowbit(idx)
        return id_code

    def update(self, idx: int, x: int, id_code: int) -> None:
        while idx > 0:
            if self.tree[idx] > x:
                self.tree[idx] = x
                self.id_rec[idx] = id_code
            idx -= BIT.lowbit(idx)


class Solution:
    @staticmethod
    def manhattanDistance(point_a: List[int], point_b: List[int]) -> int:
        return abs(point_a[0] - point_b[0]) + abs(point_a[1] - point_b[1])

    def minCostConnectPoints_MK1(self, points: List[List[int]]) -> int:
        # Kruskal
        edges = []
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                edges.append((Solution.manhattanDistance(points[i], points[j]), i, j))
        edges.sort()

        dsu = DisjointSetUnion(len(points))
        res, count = 0, 1
        for dist, a, b in edges:
            if dsu.unionSet(a, b):
                res += dist
                count += 1
                if count == len(points):
                    break
        return res

    def minCostConnectPoints_MK2(self, points: List[List[int]]) -> int:
        # Prim
        n = len(points)
        in_MST = [False] * n
        min_dist = [float('inf')] * n
        min_dist[0] = 0
        res = count = 0
        while count < n:
            cur_point, cur_distance = -1, float('inf')
            for i, point in enumerate(points):
                if not in_MST[i] and min_dist[i] < cur_distance:
                    cur_point = i
                    cur_distance = min_dist[i]
            res += cur_distance
            in_MST[cur_point] = True
            count += 1
            for i, point in enumerate(min_dist):
                if not in_MST[i]:
                    min_dist[i] = min(min_dist[i], Solution.manhattanDistance(points[cur_point], points[i]))
        return res

    def minCostConnectPoints_MK3(self, points: List[List[int]]) -> int:
        edges = []

        def build(pos: List[Tuple[int, int, int]]):
            pos.sort()
            idx_map = sorted(set([y - x for x, y, _ in pos]))
            bit = BIT(len(idx_map) + 1)
            for i in range(len(points) - 1, -1, -1):
                idx = bisect.bisect(idx_map, pos[i][1] - pos[i][0])
                j = bit.query(idx)
                if j != -1:
                    edges.append((Solution.manhattanDistance(points[pos[i][2]], points[j]), pos[i][2], j))
                bit.update(idx, pos[i][0] + pos[i][1], pos[i][2])

        def build_edges():
            pos = [(x, y, i) for i, (x, y) in enumerate(points)]
            build(pos)
            pos = [(y, x, i) for x, y, i in pos]
            build(pos)
            pos = [(-x, y, i) for x, y, i in pos]
            build(pos)
            pos = [(y, x, i) for x, y, i in pos]
            build(pos)

        build_edges()
        edges.sort()
        dsu = DisjointSetUnion(len(points))
        res, count = 0, 1
        for dist, a, b in edges:
            if dsu.unionSet(a, b):
                res += dist
                count += 1
                if count == len(points):
                    break
        return res
