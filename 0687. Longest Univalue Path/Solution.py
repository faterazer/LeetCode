class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        ans = 0

        def helper(root: TreeNode) -> int:
            if not root:
                return 0
            nonlocal ans
            left = helper(root.left)
            right = helper(root.right)
            uniLeft = uniRight = 0
            if root.left and root.left.val == root.val:
                uniLeft = left + 1
            if root.right and root.right.val == root.val:
                uniRight = right + 1
            ans = max(ans, uniLeft + uniRight)
            return max(uniLeft, uniRight)

        helper(root)
        return ans
