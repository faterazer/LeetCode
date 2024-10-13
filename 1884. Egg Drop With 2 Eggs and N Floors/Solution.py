from math import ceil, sqrt


class Solution:
    def twoEggDrop(self, n: int) -> int:
        return ceil(sqrt(8 * n + 1)) // 2
