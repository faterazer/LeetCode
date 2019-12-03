from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __sortedArrayToBSTNode(self, nums: List[int], left: int, right: int):
        if left > right:
            return None
        mid = left + (right - left) // 2
        root = TreeNode(nums[mid])
        root.left = self.__sortedArrayToBSTNode(nums, left, mid - 1)
        root.right = self.__sortedArrayToBSTNode(nums, mid + 1, right)
        return root

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.__sortedArrayToBSTNode(nums, 0, len(nums) - 1)
