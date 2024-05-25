from typing import List


class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack = []
        for i, x in enumerate(nums):
            while stack and x < stack[-1] and len(nums) - i + len(stack) > k:
                stack.pop()
            if len(stack) < k:
                stack.append(x)
        return stack
