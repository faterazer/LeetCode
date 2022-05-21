from typing import List


class Solution:
    def coinChange_MK1(self, coins: List[int], amount: int) -> int:
        dp = [0] + [amount + 1] * amount
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin < 0:
                    continue
                dp[i] = min(dp[i], dp[i - coin] + 1)
        return [dp[-1], -1][dp[-1] == amount + 1]
