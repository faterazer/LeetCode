from turtle import right
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        pre = None

        def inOrder(root: TreeNode) -> bool:
            if not root:
                return True
            if not inOrder(root.left):
                return False
            if pre and root.val <= pre.val:
                return False
            pre = root
            return inOrder(root.right)

        return inOrder(root)
