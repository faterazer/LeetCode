from typing import Coroutine, List


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        A = coordinates[1][1] - coordinates[0][1]
        B = coordinates[1][0] - coordinates[0][0]
        return all((y - coordinates[0][1]) * B == (x - coordinates[0][0]) * A for x, y in coordinates[2:])
