class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:

        def comb2(x: int) -> int:
            return x * (x - 1) // 2 if x > 1 else 0

        return comb2(n + 2) - 3 * comb2(n - limit + 1) + 3 * comb2(n - 2 * limit) - comb2(n - 3 * limit - 1)
