class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree_MK1(self, s: TreeNode, t: TreeNode) -> bool:
        def isSame(s: TreeNode, t: TreeNode) -> bool:
            if not s and not t:
                return True
            elif not s or not t or s.val != t.val:
                return False
            else:
                return isSame(s.left, t.left) and isSame(s.right, t.right)
        
        if not s:
            return False
        return isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def preOrder(root: TreeNode) -> str:
            if not root:
                return 'null'
            return "#" + str(root.val) + preOrder(root.left) + preOrder(root.right)
        return preOrder(t) in preOrder(s)
