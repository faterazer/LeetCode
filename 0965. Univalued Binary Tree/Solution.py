class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isUnivalTree(self, root: TreeNode, pre: TreeNode = None) -> bool:
        if not root:
            return True
        elif pre and pre.val != root.val:
            return False
        else:
            return self.isUnivalTree(root.left, root) and self.isUnivalTree(root.right, root)
