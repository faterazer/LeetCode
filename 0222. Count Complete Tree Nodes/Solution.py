from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def leftHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + self.leftHeight(root.left)

    def rightHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + self.rightHeight(root.right)

    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        lh, rh = self.leftHeight(root), self.rightHeight(root)
        if lh == rh:
            return 2**lh - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
