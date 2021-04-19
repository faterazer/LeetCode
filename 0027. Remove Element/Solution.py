from typing import List


class Solution:
    def removeElement_MK1(self, nums: List[int], val: int) -> int:
        '''
        双指针法
        Approach 1: Two Pointers
        '''
        i = 0
        for num in nums:
            if num != val:
                nums[i] = num
                i += 1
        return i

    def removeElement_MK2(self, nums: List[int], val: int) -> int:
        '''
        改进的双指针法，当要删除的元素很少时，速度更快
        Approach 2: Two Pointers - when elements to remove are rare
        '''
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == val:
                nums.pop(i)
        return len(nums)
