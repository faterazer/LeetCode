class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int((2 ** 0.5) * (n + 0.125) ** 0.5 - 0.5)
