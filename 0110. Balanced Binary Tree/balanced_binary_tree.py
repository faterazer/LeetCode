class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __depth(self, root: TreeNode) -> int:
        if not root:
            return 0

        left, right = self.__depth(root.left), self.__depth(root.right)
        if (left == -1 or right == -1 or abs(left - right) > 1):
            return -1
        return max(left, right) + 1

    def isBalanced(self, root: TreeNode) -> bool:
        '''
        如果以 root 为根的树是平衡树，则返回树的深度，否则返回 -1，代表树不平衡
        Return a non-negative value as the tree height, if the substree of the root node is balanced. Otherwise, -1 is returned.
        '''
        return self.__depth(root) != -1
