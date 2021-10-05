from typing import List
import numpy as np


class Solution:
    def climbStairs_MK1(self, n: int) -> int:
        '''
        Brute Force.
        '''
        return self.__climbStairs_MK1(0, n)

    def __climbStairs_MK1(self, i: int, n: int) -> int:
        if i > n:
            return 0
        elif i == n:
            return 1
        else:
            return self.__climbStairs_MK1(i + 1, n) + self.__climbStairs_MK1(i + 2, n)

    def climbStairs_MK2(self, n: int) -> int:
        '''
        Recursion with Memoization
        '''
        memo = [0] * n
        return self.__climbStairs_MK2(0, n, memo)

    def __climbStairs_MK2(self, i: int, n: int, memo: List) -> int:
        if i > n:
            return 0
        if i == n:
            return 1
        if memo[i] > 0:
            return memo[i]
        memo[i] = self.__climbStairs_MK2(
            i + 1, n, memo) + self.__climbStairs_MK2(i + 2, n, memo)
        return memo[i]

    def climbStairs_MK3(self, n: int) -> int:
        '''
        Dynamic Programming
        '''
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]

    def climbStairs_MK4(self, n: int) -> int:
        '''
        Fibonacci Number
        '''
        if n == 1 or n == 2:
            return n
        first, second = 1, 2
        for _ in range(3, n + 1):
            first, second = second, first + second
        return second

    def climbStairs_MK5(self, n: int) -> int:
        '''
        Binets Method.
        '''
        a = np.mat([[1, 1], [1, 0]])
        ans = np.mat([[1, 0], [0, 1]])
        while n:
            if n % 2 == 1:
                ans = ans * a
            a *= a
            n //= 2
        return ans[0, 0]

    def climbStairs_MK6(self, n: int) -> int:
        '''
        Fibonacci Formula
        '''
        sqrt5 = 5 ** 0.5
        fibn = ((1 + sqrt5) / 2) ** (n + 1) - ((1 - sqrt5) / 2) ** (n + 1)
        return int(fibn / sqrt5)
