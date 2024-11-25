import heapq
from math import inf
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, d in times:
            graph[u - 1].append((v - 1, d))

        dis = [inf] * n
        dis[k - 1] = 0
        pq = [(0, k - 1)]
        while pq:
            du, u = heapq.heappop(pq)
            if du > dis[u]:
                continue
            for v, d in graph[u]:
                new_dis = du + d
                if new_dis < dis[v]:
                    dis[v] = new_dis
                    heapq.heappush(pq, (new_dis, v))
        mx = max(dis)
        return mx if mx < inf else -1
