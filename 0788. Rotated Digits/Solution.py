class Solution:
    def rotatedDigits(self, N: int) -> int:
        dp = [0] * (N + 1)
        cnt = 0
        for i in range(N + 1):
            if i == 0 or i == 1 or i == 8:
                dp[i] = 1
            elif i == 2 or i == 5 or i == 6 or i == 9:
                dp[i] = 2
                cnt += 1
            else:
                a, b = dp[i // 10], dp[i % 10]
                if a == 1 and b == 1:
                    dp[i] = 1
                elif a >= 1 and b >= 1:
                    dp[i] = 2
                    cnt += 1
        return cnt
