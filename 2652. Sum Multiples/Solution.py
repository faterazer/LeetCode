class Solution:
    def sumOfMultiples(self, n: int) -> int:
        s = lambda d: n // d * d + d * (n // d) * (n // d - 1) // 2
        return s(3) + s(5) + s(7) - s(15) - s(21) - s(35) + s(105)
