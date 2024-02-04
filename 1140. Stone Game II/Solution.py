from typing import List


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n, suf_sum = len(piles), 0
        f = [[0] * (n // 2 + 2) for _ in range(n)]
        for i in range(n - 1, -1, -1):
            suf_sum += piles[i]
            for m in range(1, i // 2 + 2):
                if i + 2 * m >= n:
                    f[i][m] = suf_sum
                else:
                    f[i][m] = suf_sum - min(f[i + x][max(x, m)] for x in range(1, 2 * m + 1))
        return f[0][1]
