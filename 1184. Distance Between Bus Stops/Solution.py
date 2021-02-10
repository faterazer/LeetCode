from typing import List


class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        start, destination = sorted([start, destination])
        d = sum(distance[start:destination])
        return min(d, sum(distance) - d)
