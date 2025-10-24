from collections import defaultdict
from functools import reduce
from operator import xor


class Solution:
    # 暴力法，适合 k 值较小的情况
    def xorAfterQueries_MK1(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % MOD
        return reduce(xor, nums)

    # 商分数组，适合 k 值较大的情况
    def xorAfterQueries_MK2(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        groups = defaultdict(list)
        for l, r, k, v in queries:
            groups[k].append((l, r, v))

        for k, g in groups.items():
            buckets = defaultdict(list)
            for l, r, v in g:
                buckets[l % k].append((l, r, v))

            for start, bucket in buckets.items():
                m = (n - 1 - start) // k + 1
                diff = [1] * (m + 1)
                for l, r, v in bucket:
                    l //= k
                    diff[l] = diff[l] * v % MOD
                    r = (r - start) // k + 1
                    diff[r] = diff[r] * pow(v, -1, MOD) % MOD

                mul_d = 1
                for i in range(m):
                    mul_d = (mul_d * diff[i]) % MOD
                    j = start + i * k
                    nums[j] = (nums[j] * mul_d) % MOD
        return reduce(xor, nums)

    # 等价 MK2 的更简洁写法
    def xorAfterQueries_MK3(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        groups = defaultdict(list)
        for l, r, k, v in queries:
            groups[(k, l % k)].append((l, r, v))

        for (k, start), group in groups.items():
            m = (n - 1 - start) // k + 1
            diff = [1] * (m + 1)
            for l, r, v in group:
                l //= k
                diff[l] = diff[l] * v % MOD
                r = (r - start) // k + 1
                diff[r] = diff[r] * pow(v, -1, MOD) % MOD

            mul_d = 1
            for i in range(m):
                mul_d = (mul_d * diff[i]) % MOD
                j = start + i * k
                nums[j] = (nums[j] * mul_d) % MOD
        return reduce(xor, nums)
