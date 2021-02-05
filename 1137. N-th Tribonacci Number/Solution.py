class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n else 0
        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            a, b, c = b, c, a + b + c
        return c
