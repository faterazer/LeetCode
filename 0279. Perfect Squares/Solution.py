class Solution:
    def numSquares_MK1(self, n: int) -> int:
        """
        Time complexity: O(n√n)
        Space complexity: O(n)
        """
        dp = [float("inf")] * (n + 1)
        dp[0] = 0
        for i in range(n + 1):
            j = 1
            while j * j <= i:
                dp[i] = min(dp[i], dp[i - j * j] + 1)
                j += 1
        return dp[n]

    def numSquares_MK2(self, n: int) -> int:
        """
        四平方和定理
        Time complexity: O(√n)
        Space complexity: O(1)
        """
        def isPerfectSquare(x: int) -> bool:
            y = int(x**0.5)
            return y * y == x

        def check(x: int) -> bool:
            while x % 4 == 0:
                x /= 4
            return x % 8 == 7

        if isPerfectSquare(n):
            return 1
        if check(n):
            return 4
        for i in range(n + 1):
            if i * i > n:
                break
            if isPerfectSquare(n - i * i):
                return 2
        return 3
