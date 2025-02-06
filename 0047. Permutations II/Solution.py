import bisect
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        ans.append(nums.copy())
        while self.next_permutation(nums):
            ans.append(nums.copy())
        return ans

    def next_permutation(self, nums: List[int]) -> bool:
        r = len(nums) - 1
        while r > 0 and nums[r - 1] >= nums[r]:
            r -= 1
        if r == 0:
            return False
        nums[r:] = sorted(nums[r:])
        upper_idx = bisect.bisect_right(nums, nums[r - 1], lo=r)
        nums[r - 1], nums[upper_idx] = nums[upper_idx], nums[r - 1]
        return True
