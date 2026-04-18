class Solution:
    def mirrorDistance(self, n: int) -> int:
        rn = 0
        x = n
        while x > 0:
            x, d = divmod(x, 10)
            rn = rn * 10 + d
        return abs(n - rn)
