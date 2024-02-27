class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.diameter = 0

        def depth(root: TreeNode) -> int:
            if not root:
                return -1
            left, right = depth(root.left) + 1, depth(root.right) + 1
            self.diameter = max(self.diameter, left + right)
            return max(left, right)
        
        depth(root)
        return self.diameter
