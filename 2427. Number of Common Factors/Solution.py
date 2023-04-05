from math import gcd


class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        c, res = gcd(a, b), 0
        x = 1
        while x * x <= c:
            if c % x == 0:
                res += 1
                if x * x != c:
                    res += 1
            x += 1
        return res
