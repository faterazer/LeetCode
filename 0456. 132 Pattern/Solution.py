from typing import List


class Solution:
    def find132pattern_MK1(self, nums: List[int]) -> bool:
        stack = []
        min_k = float('-inf')
        for i in range(len(nums) - 1, -1, -1):
            while stack and stack[-1] < nums[i]:
                min_k = stack.pop()
            if nums[i] < min_k:
                return True
            stack.append(nums[i])
        return False

    def find132pattern_MK2(self, nums: List[int]) -> bool:
        stack = []
        pre_min = [float('inf')]
        for i, e in enumerate(nums):
            while stack and nums[stack[-1]] <= e:
                stack.pop()
            if stack and pre_min[stack[-1]] < e:
                return True
            stack.append(i)
            pre_min.append(min(pre_min[-1], e))
        return False
