from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root or not root.left:
            return root
        lchild, rchild = root.left, root.right
        res = self.upsideDownBinaryTree(root.left)
        root.left = root.right = None
        lchild.left = rchild
        lchild.right = root
        return res
