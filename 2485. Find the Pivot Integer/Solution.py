from math import isqrt


class Solution:
    def pivotInteger(self, n: int) -> int:
        x2 = (n**2 + n) // 2
        x = isqrt(x2)
        return x if x * x == x2 else -1
