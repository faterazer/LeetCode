import math


class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        points.sort(key=lambda p: (p[0], -p[1]))
        ans = 0
        for i in range(1, len(points)):
            c = math.inf
            for j in range(i - 1, -1, -1):
                if points[i][1] <= points[j][1] < c:
                    ans += 1
                    c = points[j][1]
        return ans
