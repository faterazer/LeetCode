from collections import defaultdict


class Solution:
    def countBadPairs(self, nums: list[int]) -> int:
        cnt = defaultdict(int)
        ans = 0
        for j, x in enumerate(nums):
            d = x - j
            ans += j - cnt[d]
            cnt[d] += 1
        return ans
