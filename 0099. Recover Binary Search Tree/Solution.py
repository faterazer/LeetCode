from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def getPredecessor(root: TreeNode) -> TreeNode:
            res = root.left
            while res.right and res.right != root:
                res = res.right
            return res

        x = y = last = None
        while root:
            if last and last.val > root.val:
                if not x:
                    x = last
                y = root
            if not root.left:
                last = root
                root = root.right
            else:
                pred = getPredecessor(root)
                if pred.right == root:
                    pred.right = None
                    last = root
                    root = root.right
                else:
                    pred.right = root
                    root = root.left

        x.val, y.val = y.val, x.val
