from math import inf
from typing import List


class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        graph = [[inf] * n for _ in range(n)]
        for x, y, w in edges:
            graph[x][y] = graph[y][x] = w

        for k in range(n):
            graph[k][k] = 0
            for i in range(n):
                for j in range(n):
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

        res, min_cnt = -1, inf
        for i in range(n):
            cnt = sum(graph[i][j] <= distanceThreshold for j in range(n))
            if cnt <= min_cnt:
                res, min_cnt = i, cnt
        return res
