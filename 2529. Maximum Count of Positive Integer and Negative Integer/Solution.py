import bisect
from typing import List


class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        neg_cnt = bisect.bisect_left(nums, 0)
        pos_cnt = len(nums) - bisect.bisect_right(nums, 0)
        return max(neg_cnt, pos_cnt)
