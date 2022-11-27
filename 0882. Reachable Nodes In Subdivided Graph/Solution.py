from collections import defaultdict
import heapq
from typing import List


class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        E = defaultdict(dict)
        for u, v, cnt in edges:
            E[u][v] = E[v][u] = cnt + 1
        seen = {}
        pq = [(-maxMoves, 0)]
        while pq:
            remain_moves, node = heapq.heappop(pq)
            if node not in seen:
                seen[node] = remain_moves = -remain_moves
                for neighbour, cnt in E[node].items():
                    if neighbour not in seen and remain_moves - cnt >= 0:
                        heapq.heappush(pq, (cnt - remain_moves, neighbour))
        res = len(seen)
        for u, v, cnt in edges:
            res += min(seen.get(u, 0) + seen.get(v, 0), cnt)
        return res
