import heapq
from typing import List


class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        graph = [[] for _ in range(n)]
        for u, v, d in edges:
            graph[u].append((v, d))
            graph[v].append((u, d))

        dist = [-1] * n
        dist[0] = 0
        pq = [(0, 0)]
        while pq:
            dx, x = heapq.heappop(pq)

            if dx > dist[x]:
                continue

            for y, d in graph[x]:
                new_dist = dx + d
                if new_dist < disappear[y] and (dist[y] == -1 or new_dist < dist[y]):
                    dist[y] = new_dist
                    heapq.heappush(pq, (new_dist, y))
        return dist
