from collections import deque
from typing import List


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]

        adj = [[] for _ in range(n)]
        degree = [0] * n
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
            degree[a] += 1
            degree[b] += 1

        queue = deque([i for i in range(n) if degree[i] == 1])
        remain = n
        while remain > 2:
            size = len(queue)
            remain -= size
            for _ in range(size):
                node = queue.popleft()
                for neighbour in adj[node]:
                    degree[neighbour] -= 1
                    if degree[neighbour] == 1:
                        queue.append(neighbour)

        return list(queue)
