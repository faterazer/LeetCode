from collections import defaultdict
from functools import reduce
from math import isqrt
from operator import xor


class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        B = isqrt(len(queries))
        groups = defaultdict(list)
        for l, r, k, v in queries:
            if k < B:
                groups[(k, l % k)].append((l, r, v))
            else:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % MOD

        n = len(nums)
        for (k, start), group in groups.items():
            m = (n - start - 1) // k + 1
            diff = [1] * (m + 1)
            for l, r, v in group:
                l = (l - start) // k
                r = (r - start) // k + 1
                diff[l] = diff[l] * v % MOD
                diff[r] = diff[r] * pow(v, -1, MOD) % MOD
            mul_d = 1
            for i in range(m):
                mul_d = mul_d * diff[i] % MOD
                j = start + i * k
                nums[j] = nums[j] * mul_d % MOD
        return reduce(xor, nums)
