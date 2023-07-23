class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        if n == 2:
            return k * k
        last1, last2 = k, k * k
        res = 0
        for _ in range(2, n):
            res = last1 * (k - 1) + last2 * (k - 1)
            last1 = last2
            last2 = res
        return res
