from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for i in range(1 << len(nums)):
            subset = [x for j, x in enumerate(nums) if i >> j & 1]
            ans.append(subset)
        return ans
