class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor_MK1(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        '''
        Recursive
        '''
        rval, pval, qval = root.val, p.val, q.val
        if pval < rval and qval < rval:
            return self.lowestCommonAncestor_MK1(root.left, p, q)
        elif pval > rval and qval > rval:
            return self.lowestCommonAncestor_MK1(root.right, p, q)
        else:
            return root

    def lowestCommonAncestor_MK2(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        '''
        Iterative
        '''
        pval, qval = p.val, q.val
        curr = root
        while curr:
            if pval < curr.val and qval < curr.val:
                curr = curr.left
            elif pval > curr.val and qval > curr.val:
                curr = curr.right
            else:
                return curr
