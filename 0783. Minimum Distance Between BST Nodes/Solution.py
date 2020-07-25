class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        stack = []
        pre, p = None, root
        ans = float('inf')
        while p or stack:
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            if pre:
                ans = min(ans, abs(p.val - pre.val))
            pre = p
            p = p.right
        return ans
