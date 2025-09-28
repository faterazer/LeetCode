class Solution:
    def maxProfit(self, prices: list[int], strategy: list[int], k: int) -> int:
        total = s = 0
        for p, st in zip(prices[: k // 2], strategy[: k // 2]):
            total += p * st
            s -= p * st
        for p, st in zip(prices[k // 2 : k], strategy[k // 2 : k]):
            total += p * st
            s += p * (1 - st)

        max_s = max(0, s)
        for i in range(k, len(prices)):
            p, st = prices[i], strategy[i]
            total += p * st
            s += p * (1 - st) - prices[i - k // 2] + prices[i - k] * strategy[i - k]
            max_s = max(max_s, s)
        return total + max_s
