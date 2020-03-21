import math


class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if not x or not y:
            return z == 0 or (x + y) == z
        return z % math.gcd(x, y) == 0
