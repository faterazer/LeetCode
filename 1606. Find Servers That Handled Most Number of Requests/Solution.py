import heapq
from typing import List


class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        available = list(range(k))
        busy = []
        cnt = [0] * k
        for i, (beg, span) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= beg:
                _, server_id = heapq.heappop(busy)
                heapq.heappush(available, i + (server_id - i) % k)
            if available:
                server_id = heapq.heappop(available) % k
                cnt[server_id] += 1
                heapq.heappush(busy, (beg + span, server_id))
        maximum = max(cnt)
        return [i for i, e in enumerate(cnt) if e == maximum]
