class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def C2(x: int) -> int:
            return x * (x - 1) // 2 if x > 1 else 0

        return C2(n + 2) - 3 * C2(n - limit + 1) + 3 * C2(n - limit * 2) - C2(n - limit * 3 - 1)
