from typing import List


class Solution:
    def maxSubArray_MK1(self, nums: List[int]) -> int:
        '''
        DP. 动态规划
        '''
        maximum = nums[0]
        temp = nums[0]
        for i in range(1, len(nums)):
            if temp < 0:
                temp = nums[i]
            else:
                temp += nums[i]
            maximum = max(maximum, temp)
        return maximum

    def maxSubArray_MK2(self, nums: List[int]) -> int:
        '''
        Divide-and-conquer. 分治法
        '''
        return self.findMaxSubArray(nums, 0, len(nums) - 1)

    def findMaxSubArray(self, nums: List[int], left: int, right: int) -> int:
        if left == right:
            return nums[left]
        else:
            mid = left + (right - left) // 2
            left_max = self.findMaxSubArray(nums, left, mid)
            right_max = self.findMaxSubArray(nums, mid+1, right)
            mid_max = self.findMaxCrossingSubArray(nums, left, mid, right)
            return max(left_max, mid_max, right_max)

    def findMaxCrossingSubArray(self, nums: List[int], left: int, mid: int, right: int) -> int:
        maximum, temp, i = nums[mid], nums[mid], mid - 1
        while i >= left:
            temp += nums[i]
            maximum = max(temp, maximum)
            i -= 1
        temp, i = maximum, mid + 1
        while i <= right:
            temp += nums[i]
            maximum = max(temp, maximum)
            i += 1
        return maximum
