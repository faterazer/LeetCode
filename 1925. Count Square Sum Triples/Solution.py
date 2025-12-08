from math import gcd


class Solution:
    def countTriples(self, n: int) -> int:
        result = 0
        u = 3
        while u * u < 2 * n:
            v = 1
            while v < u and u * u + v * v <= n * 2:
                if gcd(u, v) == 1:
                    result += n * 2 // (u * u + v * v)
                v += 2
            u += 2
        return result * 2
