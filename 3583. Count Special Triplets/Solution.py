from collections import Counter, defaultdict


class Solution:
    def specialTriplets(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        suf_cnt = Counter(nums)
        result = 0
        pre_cnt = defaultdict(int)
        for x in nums:
            suf_cnt[x] -= 1
            result += pre_cnt[x * 2] * suf_cnt[x * 2]
            pre_cnt[x] += 1
        return result % MOD
