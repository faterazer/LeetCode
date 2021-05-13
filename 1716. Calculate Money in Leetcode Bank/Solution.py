class Solution:
    def totalMoney(self, n: int) -> int:
        weeks, days = n // 7, n % 7
        return weeks * 28 + weeks * (weeks - 1) * 7 // 2 + (weeks + 1) * days + days * (days - 1) // 2
