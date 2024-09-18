from collections import defaultdict, deque
from typing import List


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0

        stop2buses = defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                stop2buses[stop].append(i)
        if source not in stop2buses or target not in stop2buses:
            return -1

        queue = deque([source])
        visited = set([source])
        cnt = 0
        while queue:
            qsize = len(queue)
            cnt += 1
            for _ in range(qsize):
                x = queue.popleft()
                for i in stop2buses[x]:
                    for y in routes[i]:
                        if y in visited:
                            continue
                        if y == target:
                            return cnt
                        visited.add(y)
                        queue.append(y)
                    routes[i].clear()
        return -1
