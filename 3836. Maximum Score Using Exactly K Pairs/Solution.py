from math import inf


class Solution:
    def maxScore(self, nums1: list[int], nums2: list[int], k: int) -> int:
        n, m = len(nums1), len(nums2)
        f = [[0] * (m + 1) for _ in range(n + 1)]
        g = [[0] * (m + 1) for _ in range(n + 1)]
        invalid = [-inf] * (m - k + 1)
        for K in range(1, k + 1):
            g[K - 1][K : -(k - K)] = invalid
            for i in range(K, n + 1 - (k - K)):
                g[i][K - 1] = -inf
                for j in range(K, m + 1 - (k - K)):
                    g[i][j] = max(g[i - 1][j], g[i][j - 1], f[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1])
            f, g = g, f
        return f[n][m]
