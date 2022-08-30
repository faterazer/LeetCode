from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        node, cur = TreeNode(val), root
        if root.val < val:
            node.left = root
            return node
        while cur.right and cur.right.val > val:
            cur = cur.right
        node.left = cur.right
        cur.right = node
        return root
