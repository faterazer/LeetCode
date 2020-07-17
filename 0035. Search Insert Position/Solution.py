from typing import List


class Solution:
    def searchInsert_MK1(self, nums: List[int], target: int) -> int:
        '''
        linear search. 线性搜索
        '''
        return len([x for x in nums if x < target])

    def searchInsert_MK2(self, nums: List[int], target: int) -> int:
        '''
        use built-in function. 适用内建函数
        '''
        if target in nums:
            return nums.index(target)
        else:
            nums.append(target)
            nums.sort()
            return nums.index(target)

    def searchInsert_MK3(self, nums: List[int], target: int) -> int:
        '''
        binary search. 二分查找
        '''
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                return mid
        return left
