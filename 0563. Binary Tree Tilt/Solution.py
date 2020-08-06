class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.tilt = 0

    def findTilt(self, root: TreeNode) -> int:
        def postOrder(root: TreeNode) -> int:
            if not root:
                return 0
            left = postOrder(root.left)
            right = postOrder(root.right)
            self.tilt += abs(left - right)
            return root.val + left + right
        postOrder(root)
        return self.tilt
