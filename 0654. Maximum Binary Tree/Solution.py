from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        stack = []
        for e in nums:
            p = TreeNode(e)
            while stack and stack[-1].val < e:
                p.left = stack.pop()
            if stack:
                stack[-1].right = p
            stack.append(p)
        return stack[0]
