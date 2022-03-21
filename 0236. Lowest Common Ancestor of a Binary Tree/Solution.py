from turtle import right


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q:
            return root

        lp = self.lowestCommonAncestor(root.left, p, q)
        rp = self.lowestCommonAncestor(root.right, p, q)
        if lp and rp:
            return root
        elif lp or rp:
            return lp if lp else rp
        else:
            return None
