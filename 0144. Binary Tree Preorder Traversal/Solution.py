from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal_MK1(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def preorder(root: TreeNode) -> None:
            if not root:
                return
            res.append(root.val)
            preorder(root.left)
            preorder(root.right)

        preorder(root)
        return res

    def preorderTraversal_MK2(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res

        stack = [root]
        while stack:
            p = stack.pop()
            res.append(p.val)
            if p.right:
                stack.append(p.right)
            if p.left:
                stack.append(p.left)
        return res

    def preorderTraversal_MK3(self, root: Optional[TreeNode]) -> List[int]:
        def getSuccessor(root: TreeNode) -> TreeNode:
            res = root.left
            while res.right and res.right != root:
                res = res.right
            return res

        res, cur = [], root
        while cur:
            if cur.left:
                succ = getSuccessor(cur)
                if succ.right == cur:
                    succ.right = None
                    cur = cur.right
                else:
                    res.append(cur.val)
                    succ.right = cur
                    cur = cur.left
            else:
                res.append(cur.val)
                cur = cur.right
        return res
