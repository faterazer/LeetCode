import math


class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        n = int(math.cbrt(neededApples / 4))
        if 2 * n * (n + 1) * (2 * n + 1) < neededApples:
            n += 1
        return 8 * n
