class Solution:
    def myPow(self, x: float, n: int) -> float:
        if not x:
            return 0.0
        if n < 0:
            return 1 / x * self.myPow(1 / x, -(n + 1))
        res = 1.0
        while n:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res
