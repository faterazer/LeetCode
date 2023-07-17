from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        res = root.val
        while root:
            if abs(root.val - target) < abs(res - target) or (
                abs(root.val - target) == abs(res - target) and root.val < res
            ):
                res = root.val
            if root.val > target:
                root = root.left
            else:
                root = root.right
        return res
