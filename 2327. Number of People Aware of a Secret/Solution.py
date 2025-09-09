class Solution:
    def peopleAwareOfSecret_MK1(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        dp = [0] * n
        dp[0] = 1
        slide_sum = 0
        for i in range(1, n):
            if i >= delay:
                slide_sum += dp[i - delay]
            if i >= forget:
                slide_sum -= dp[i - forget]
            dp[i] = slide_sum % MOD
        return sum(dp[n - forget :]) % MOD

    def peopleAwareOfSecret_MK2(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        pre_sum = [0] * (n + 1)
        pre_sum[1] = 1
        for i in range(2, n + 1):
            pre_sum[i] = pre_sum[i - 1]
            if i > delay:
                pre_sum[i] += pre_sum[i - delay]
            if i > forget:
                pre_sum[i] -= pre_sum[i - forget]
            pre_sum[i] %= MOD
        return (pre_sum[n] - pre_sum[n - forget]) % MOD
