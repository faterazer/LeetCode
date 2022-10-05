from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if not root:
            return None
        if depth == 1:
            return TreeNode(val, root)
        if depth == 2:
            root.left = TreeNode(val, root.left)
            root.right = TreeNode(val, right=root.right)
            return root
        root.left = self.addOneRow(root.left, val, depth - 1)
        root.right = self.addOneRow(root.right, val, depth - 1)
        return root
