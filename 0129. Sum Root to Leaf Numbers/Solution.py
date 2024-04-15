from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumNumbers(self, root: Optional[TreeNode], accum: int = 0) -> int:
        if root is None:
            return 0
        accum = accum * 10 + root.val
        if root.left is None and root.right is None:
            return accum
        return self.sumNumbers(root.left, accum) + self.sumNumbers(root.right, accum)
