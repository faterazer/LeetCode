from collections import defaultdict
from typing import List


class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        res = i = 0
        for j, x in enumerate(nums):
            cnt[x] += 1
            while j - i + 1 - cnt[nums[i]] > k:
                cnt[nums[i]] -= 1
                i += 1
            res = max(res, cnt[x])
        return res
