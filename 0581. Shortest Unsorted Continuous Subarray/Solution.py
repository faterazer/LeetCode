from typing import List


class Solution:
    # Time complexity: O(n)
    # Space complexity: O(1)
    def findUnsortedSubarray_MK1(self, nums: List[int]) -> int:
        beg, end = 0, len(nums) - 1
        while beg < len(nums) - 1 and nums[beg] <= nums[beg + 1]:
            beg += 1
        if beg == len(nums) - 1:
            return 0
        while end > 0 and nums[end] >= nums[end - 1]:
            end -= 1
        maxItem, minItem = float('-inf'), float('inf')
        for i in range(beg, end + 1):
            maxItem = max(maxItem, nums[i])
            minItem = min(minItem, nums[i])
        beg = 0
        while nums[beg] <= minItem:
            beg += 1
        end = len(nums) - 1
        while nums[end] >= maxItem:
            end -= 1
        return end - beg + 1

    # More concise.
    # Time complexity: O(n)
    # Space complexity: O(1)
    def findUnsortedSubarray_MK2(self, nums: List[int]) -> int:
        maxItem, minItem = nums[0], nums[-1]
        beg, end = -1, -2
        size = len(nums)
        for i in range(1, size):
            maxItem = max(maxItem, nums[i])
            minItem = min(minItem, nums[size - 1 - i])
            if nums[i] < maxItem:
                end = i
            if nums[size - 1 - i] > minItem:
                beg = size - 1 - i
        return end - beg + 1
