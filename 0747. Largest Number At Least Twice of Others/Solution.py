from typing import List


class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        index, second = 0, -1
        for i in range(1, len(nums)):
            if nums[i] > nums[index]:
                second = nums[index]
                index = i
            elif nums[i] > second:
                second = nums[i]
        return index if second * 2 <= nums[index] else -1
