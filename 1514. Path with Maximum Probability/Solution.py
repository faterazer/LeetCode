import heapq
from typing import List


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = [[] for _ in range(n)]
        for (a, b), p in zip(edges, succProb):
            graph[a].append((p, b))
            graph[b].append((p, a))

        pq = [(-1.0, start_node)]
        visited = [False] * n
        while pq:
            prob, node = heapq.heappop(pq)
            if node == end_node:
                return -prob
            visited[node] = True
            for p, x in graph[node]:
                if not visited[x]:
                    heapq.heappush(pq, (p * prob, x))
        return 0.0
