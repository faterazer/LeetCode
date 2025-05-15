import numpy as np


class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: list[int]) -> int:
        MOD = 10**9 + 7
        M = [[0] * 26 for _ in range(26)]
        for i, x in enumerate(nums):
            for j in range(1, x + 1):
                M[(i + j) % 26][i] += 1
        v = [0] * 26
        for c in s:
            v[ord(c) - ord("a")] += 1
        M = np.array(M, dtype=object)
        v = np.array(v, dtype=object).reshape(26, 1)

        while t:
            if t & 1:
                v = M @ v % MOD
            M = M @ M % MOD
            t >>= 1

        return np.sum(v) % MOD
