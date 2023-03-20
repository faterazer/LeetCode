from collections import Counter
from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        pos = nums.index(k)
        cnt, bal = Counter({0: 1}), 0
        for i in range(pos - 1, -1, -1):
            bal += 1 if nums[i] < k else -1
            cnt[bal] += 1

        res, bal = cnt[0] + cnt[-1], 0
        for i in range(pos + 1, len(nums)):
            bal += 1 if nums[i] > k else -1
            res += cnt[bal] + cnt[bal - 1]
        return res
